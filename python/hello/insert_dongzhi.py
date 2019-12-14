
import pymysql
import paramiko
import os
import time
import threading
import multiprocessing
import re
import datetime
import sys
import json
import getpass
import logging
import daemon
from subprocess import PIPE, Popen


def data_prepare(proxy_ip, proxy_port, mysql_user, mysql_password, testdb, test_table_size):
    db = None
    try:
        db = pymysql.connect(host=proxy_ip, port=int(proxy_port), user=mysql_user, password=mysql_password, autocommit=True)
        cursor = db.cursor(pymysql.cursors.DictCursor)
        query = 'create database if not exists '+testdb
        cursor.execute(query)
        cursor.execute('use '+testdb)
        query = 'create table sbtest1(id int primary key, value int) '
        cursor.execute(query)
        time.sleep(5)

        rows = test_table_size
        cursor.execute('begin')
        query = 'insert into sbtest1(id, value) values(1, 10000)'
        for i in xrange(2,rows+1):
            query += ',(' + str(i)+','+'10000)'
        cursor.execute(query)
        cursor.execute('commit')
        cursor.close()
    except pymysql.err.MySQLError as e:
        print(query+" "+str(e))
    finally:
        if db:
            db.close()

if __name__ == "__main__":
    proxy_ip = sys.argv[1]
    proxy_port = int(sys.argv[2])
    proxy_user = sys.argv[3]
    proxy_pass = sys.argv[4]
    testdb = sys.argv[5]
    test_table_size = int(sys.argv[6])
    data_prepare(proxy_ip, proxy_port, proxy_user, proxy_pass, testdb, test_table_size)

