#coding=utf-8

import threading
import time
import pymysql
import random
import os

out = 0

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
        random_num()




def random_num():
   while(True):
       num = random.randint(1, 100)
       print("num:{0}".format(num))
       if (num == 50):

           global out
           print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
           print("out:{0}".format(out))
           out = 1


class ThreadManager():#线程管理类

    thread_list = []
    def __init__(self,thread_num):
        self.thread_num = thread_num

    def create_thread(self):
        for i in range(0,self.thread_num):
            thread_name = 'thread {}'.format(str(i))
            addThread = myThread(i,thread_name,10,0)#创建线程
            self.thread_list.append(addThread)

    def start_thread(self):
        for i in range(len(self.thread_list)):
            self.thread_list[i].start()





def check():
    while 1:
        print("@@@@@@@out:{0}".format(str(out)))
        time.sleep(1)
        if(1 == out):
            print("############################")
            try:
                os._exit(0)
            except:
                print("exit error")



def main():



    threading.Thread(target = check).start()

    myThreadManger = ThreadManager(10)
    myThreadManger.create_thread()
    myThreadManger.start_thread()





if __name__ == '__main__':
    main()