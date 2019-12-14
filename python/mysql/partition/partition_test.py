#!/usr/bin/python

import pymysql
import random
import time


#partition_start = 1001
#partition_value = 700000 
partition_curr_name = 0
partition_curr_value = 0

#able to delete name
num = []

db = pymysql.connect(host="9.77.14.120",port=24129,user="walter",passwd="123456",db="test")
cursor = db.cursor()

def do_connect_db():
    #db = pymysql.connect(host="9.77.14.120",port=24129,user="walter",passwd="123456",db="test")
    #cursor = db.cursor()
    try:
        query = "select version()"
        cursor.execute(query)
        result = cursor.fetchall()
        print(result)

        sql = """CREATE TABLE if not exists part_test (
        id INT NOT NULL,
        my_date DATE NOT NULL DEFAULT '1970-01-01',
        age INT NOT NULL,
        primary key(id,my_date))
        PARTITION BY RANGE (to_days(my_date)) (
        PARTITION p1000 VALUES LESS THAN (700000));
        """
        cursor.execute(sql)
        result = cursor.fetchall()
        print("create table succ")
    except:
        print("create table failed.res:")
        print(result)

def do_check():
    print("=====do_check=====")
    #get max partition name
    try:
        sql = """select PARTITION_NAME,PARTITION_DESCRIPTION  from information_schema.partitions where table_name = 'part_test';
        """
        cursor.execute(sql)
        result = cursor.fetchall()
        print(result)
        p_name = ""
        p_value = ""

        for value in result:
            p_name = value[0]
            num.append(int(p_name[1:]))
            p_value = value[1]
        print(p_name)
        p_name = p_name[1:]
        #p_value = p_value[1:]

        #print(p_name)
        #chaneg string to int => partition_curr
        global partition_curr_name
        partition_curr_name = int(p_name)
        global partition_curr_value
        partition_curr_value = int(p_value)
        print(partition_curr_value)
    except:
        print("get default partition information error")
        exit()


def do_add_partition(name,value):
    print("=====do_add_partition=====")
    print(partition_curr_name)
    try:
        sql = "alter table part_test add partition (partition p" + str(name) + " values less than (" + str(value) + "));"
        print(sql)
        cursor.execute(sql)
        #global partition_curr
        #partition_curr = name
        #partition_value = value
    except:
        print("add partition error.%s"%(sql))
        exit()


def do_delete_partition(name):
    print("=====do_delete_partition=====")
    print(partition_curr_value)
    try:
        sql = "alter table part_test drop partition p" + str(name) + ";"
        print(sql)
        cursor.execute(sql)
    except:
        print("drop partition error.sql%s"%(sql))
        exit()


if __name__ == "__main__":

    do_connect_db()
    do_check()
    while True:
        value = random.randint(10, 20)
        print("random value:%d"%(value))
        if 0 == value%2:#add partition
            do_add_partition(partition_curr_name+1,partition_curr_value+value)
            global partition_curr_name
            partition_curr_name = partition_curr_name + 1
            global partition_curr_value 
            partition_curr_value += value
            num.append(partition_curr_name)
            print("add num:",num)
        else:#delete_partition
            if 0 == len(num):#no delete
                continue
            del_value = random.randint(1,len(num)) - 1
            do_delete_partition(num[del_value])
            print("del num %d"%(del_value))
            num.remove(num[del_value])
            print("del num",num)
            
        
        time.sleep(0.1)













    #do_add_partition(1002,710000)
    #do_delete_partition(1002)
