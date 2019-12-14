# coding=utf-8

import threading
import time
import pymysql
import random

'''
def job():
    print('This is an added thread,numbwer is %s' % threading.current_thread)

def main():

    for i in range(1,5):
        added_thread = threading.Thread(target = job)
        added_thread.start()


    print(threading.active_count())
    print(threading.enumerate())
    print(threading.current_thread())
    :return: 

if __name__ == '__main__':
    main()
'''


class myThread(threading.Thread):  # 线程类
    def __init__(self, threadID, name, counter, delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.delay = delay

    def run(self):
        print("start " + self.name)
        # print_time(self.name,self.delay,self.counter)
        db = myDB(ip='127.0.0.1', port=4000, user='root', db='test', num=10000)
        db.execSql(self.counter)


'''
def print_time(threadNmae,delay,counter):
    while counter:
        time.sleep(delay)
        print("%s %s" % (threadNmae,time.ctime(time.time())))
        counter -= 1
'''


class ThreadManager():  # 线程管理类

    thread_list = []

    def __init__(self, thread_num):
        self.thread_num = thread_num

    def create_thread(self):
        for i in range(0, self.thread_num):
            thread_name = 'thread {}'.format(str(i))
            addThread = myThread(i, thread_name, 10, 0)  # 创建线程
            self.thread_list.append(addThread)

    def start_thread(self):
        for i in range(len(self.thread_list)):
            self.thread_list[i].start()


class myDB():

    def __init__(self, ip, port, user, db, num):
        self.ip = ip
        self.port = port
        self.user = user
        self.db = db
        self.num = num
        self.dbTest = pymysql.connect(host=self.ip, port=self.port, user=self.user, db=self.db)
        # self.dbTest = pymysql.connect(host=self.ip, port=self.port, passwd = '158776zx',user=self.user, db=self.db)
        self.cursor = self.dbTest.cursor()

    def execSql(self, count):  # count为sql执行的次数
        for i in range(0, count):
            num1 = random.randint(1, self.num)
            num2 = random.randint(1, self.num)

            sql1 = 'select age from test1 where id = {}'.format(str(num1))

            print(sql1)

            self.cursor.execute(sql1)
            data = self.cursor.fetchone()
            if (data[0] > -1):
                try:
                    sql2 = 'update test1 set age = age - 1 where id = {}'.format(str(num1))
                    sql3 = 'update test1 set age = age + 1 where id = {}'.format(str(num2))
                    print(sql2)
                    print(sql3)
                    self.cursor.execute(sql2)
                    self.cursor.execute(sql3)
                    self.dbTest.commit()
                    print("commit")

                    sql = 'select sum(age) from test1;'
                    self.cursor.execute(sql)
                    data = self.cursor.fetchall()
                    print("sum:{}".format(data))


                except:
                    self.dbTest.rollback()
                    print("rollback")

            i = i + 1
            print("R:{}".format(str(i)))


def main():
    '''
    thread1 = myThread(1,"Thread1",5,0)
    thread2 = myThread(2,"Thread2",3,0)

    thread1.start()
    thread2.start()
    :return:
    '''

    myThreadManger = ThreadManager(10)
    myThreadManger.create_thread()
    myThreadManger.start_thread()


if __name__ == '__main__':
    main()