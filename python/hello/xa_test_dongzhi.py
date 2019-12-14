#!/usr/bin/python
# -*- coding: UTF-8 -*-

import threading
import time
import pymysql
import random
import multiprocessing
import signal
import sys
from multiprocessing import Queue, Value, Process
import mysql.connector
import logging

ER_ERROR_LAST = 1727
ER_LOG_GTID_TIMEOUT = ER_ERROR_LAST + 1

proxy_ip = ''
proxy_port = ''
proxy_user = ''
proxy_pass = ''
testdb = ''
test_table_size = ''
logger = logging.getLogger('check_balance_logger')
logger.setLevel(logging.DEBUG)

fh = logging.FileHandler('check_balance.log')
fh.setLevel(logging.DEBUG)

ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)

formatter = logging.Formatter(
    "%(asctime)s %(pathname)s %(filename)s %(funcName)s %(lineno)s %(levelname)s - %(message)s", "%Y-%m-%d %H:%M:%S")
fh.setFormatter(formatter)
ch.setFormatter(formatter)

logger.addHandler(fh)
logger.addHandler(ch)


def do_test(process_name, run_time, committedTrx, failedTrx, need_exit):
    start_time = time.time()
    while time.time() - start_time < run_time and need_exit.value == 0:
        try:
            cursor = None
            db = None
            succ = True
            db = mysql.connector.connect(host=proxy_ip, port=proxy_port, user=proxy_user, password=proxy_pass,
                                         database=testdb, connect_timeout=10, autocommit=True)
            cursor = db.cursor()
            cursor.execute("begin")
            # cursor.execute("select gtid()")
            # gtid = cursor.fetchall()[0][0]
            # print gtid
            # query = "insert into check_gtid(xid) values('"+gtid+"')"
            # cursor.execute(query)
            for v in ['-4', '-6', '-7', '+6', '+6', '+5']:
                query = "update sbtest1 set value=value" + v + " where id=" + str(random.randint(1, test_table_size))
                cursor.execute(query)
                if cursor.rowcount != 1:
                    logger.debug("%s query ret is %d" % (query, cursor.rowcount))
                    # cursor.execute("rollback")
                    succ = False
                    with failedTrx.get_lock():
                        failedTrx.value += 1
                    break
            # cursor.execute("select gtid()")
            # gtid = cursor.fetchall()[0][0]
            # query = "delete from check_gtid where xid='"+gtid+"'"
            # cursor.execute(query)
            if succ:
                cursor.execute("commit")
                with committedTrx.get_lock():
                    committedTrx.value += 1
                sql = "select sum(value) from sbtest1";
                cursor.execute(sql)
                sum_value = int(cursor.fetchone()[0])
                if sum_value != 10240000000:
                    print("current sum value is %d" % (sum_value))
                    with need_exit.get_lock():
                        need_exit.value = 1
        except mysql.connector.Error as e:
            # print process_name, str(e)
            with failedTrx.get_lock():
                failedTrx.value += 1
        except IndexError as e:
            pass
        finally:
            if db:
                db.close()


def run_test_process(process_num, run_time):
    committedTrx = Value('d', 0)
    failedTrx = Value('d', 0)
    need_exit = Value('d', 0)
    process_arr = []
    try:
        for i in xrange(process_num):
            processName = "Process-" + str(i)
            p = Process(target=do_test, args=(processName, run_time, committedTrx, failedTrx, need_exit))
            p.start()
            process_arr.append(p)
    except Exception as e:
        print "Error: unable to start process", str(e)
    for p in process_arr:
        p.join()

    print '---------------------------------------------------'
    print "committed_trx: ", committedTrx.value
    print "failed_trx:    ", failedTrx.value
    print '---------------------------------------------------'


def handler(signum, frame):
    pass


if __name__ == "__main__":
    proxy_ip = sys.argv[1]
    proxy_port = int(sys.argv[2])
    proxy_user = sys.argv[3]
    proxy_pass = sys.argv[4]
    testdb = sys.argv[5]
    test_table_size = int(sys.argv[6])
    # signal.signal(signal.SIGINT, handler)
    # signal.signal(signal.SIGTERM, handler)
    process_num = int(sys.argv[7])
    run_time = int(sys.argv[8])
    run_test_process(process_num, run_time)

    print "all test completed!!!"

'''
def check_trx():
    global committedTrx, failedTrx, needCheckTrx, is_exit
    committed = 0
    failed = 0
    while not is_exit:
        gtid = ""
        try:
            db = pymysql.connect(host=testHost, port=testPort, user=testUser, password=testPassword, database=testDatabase)
            cursor = db.cursor()

            for gtid in needCheckTrx:
                state = ""
                query = "select gtid_state('" + gtid + "')"
                rows = cursor.execute(query)
                if rows != 0:
                    state = cursor.fetchone()[2]

                if state == "commit":
                    committed += 1
                    #print "gtid:", gtid, " will be commit by agent!"
                else:
                    failed += 1
                    #print "gtid:", gtid, " will be roll back by agent!"
        except pymysql.err.MySQLError as e:
            #print gtid, e
            time.sleep(4)
            committed = 0
            failed = 0
            continue
        else:
            committedTrx.value += committed
            failedTrx.value += failed
            return
'''

