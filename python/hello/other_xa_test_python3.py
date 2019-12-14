#coding=utf-8

import threading
import time
import pymysql
import random
import sys



out = 0
thread_num = 10
var_num = ['-1','+4','-3','+5','-6','+1']

class myThread(threading.Thread):#线程类
    def __init__(self,threadID,name,counter,delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.delay = delay


    def run(self):
        print("start " + self.name)
        #print_time(self.name,self.delay,self.counter)
        #db = myDB(ip='127.0.0.1', port=4000, user='root', db='test', num=1000)
        db = myDB(ip='127.0.0.1', port=3306, user='root', db='test', num=1000)
        db.execSql(self.counter)




class ThreadManager():#线程管理类

    thread_list = []
    def __init__(self,thread_num):
        self.thread_num = thread_num

    def create_thread(self):
        for i in range(0,self.thread_num):
            thread_name = 'thread {}'.format(str(i))
            addThread = myThread(i,thread_name,100,0)#创建线程
            self.thread_list.append(addThread)

    def start_thread(self):
        for i in range(len(self.thread_list)):
            self.thread_list[i].start()

    def join_thread(self):
        for i in range(len(self.thread_list)):
            threading.Thread.join(self.thread_list[i])




class myDB():

    def __init__(self,ip,port,user,db,num):
        self.ip = ip
        self.port = port
        self.user = user
        self.db = db
        self.num = num
        #self.dbTest = pymysql.connect(host=self.ip,port=self.port,user=self.user,db=self.db)
        self.dbTest = pymysql.connect(host=self.ip, port=self.port, passwd = '158776zx',user=self.user, db=self.db)
        self.cursor = self.dbTest.cursor()


    def execSql(self,count):#count为sql执行的次数
        for i in range(0,count):
            try:
                self.cursor.execute("set session transaction isolation level read committed;")
                self.cursor.execute("begin")
                for j in range(0, 6):
                    global var_num
                    rand_num = random.randint(1, self.num)

                    calc_sql = 'update test1 set age = age ' + var_num[j] + ' where id = {}'.format(str(rand_num))
                    print("cal_sql:{0}".format(calc_sql))


                    self.cursor.execute(calc_sql)

                self.cursor.execute("commit")
                print("commit")

                sql = 'select sum(age) from test1;'
                self.cursor.execute(sql)
                data = self.cursor.fetchone()
                if (int(data[0]) != 20000000):
                    print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
                    global out
                    out = 1
                    print("bad_sum:{}".format(data))
                print("sum:{}".format(data))

            except:
                # self.dbTest.rollback()
                self.cursor.execute("rollback")
                print("rollback")

            i = i + 1
            print("R:{}".format(str(i)))


        global thread_num
        print("finish_up:{0}".format(str(thread_num)))
        thread_num = thread_num -1
        print("finish_down:{0}".format(str(thread_num)))





def check():
    global thread_num
    while 1:
        time.sleep(0.1)
        print("check{0}".format(str(thread_num)))
        if(0 == int(thread_num)):
            print("finish")
            break

        if(1 == out):
            print("sql_error")
            break

    sys.exit()

def main():

    try:
        check_thread = threading.Thread(target = check)
        check_thread.start()

        #threading.Thread.join(check_thread)
    except:
        print("check error")

    myThreadManger = ThreadManager(thread_num)
    myThreadManger.create_thread()
    myThreadManger.start_thread()




if __name__ == '__main__':
    main()