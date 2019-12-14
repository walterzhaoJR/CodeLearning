#!/usr/bin/python
# -*- coding: UTF-8 -*-
#####################################
##    created by basededato        ##
##    2018-03-24                   ##
#####################################

import pymysql
import time
# 脚本执行时间，以保证session_BB 与 session_AA  的输出时间差小于  下面的sleep time
print(time.asctime( time.localtime(time.time()) ))

conn= pymysql.connect(
            host        = '192.168.121.217',
            port        = 5919,
            user        = 'root',
            passwd      = 'root',
            db          = 'uat_exue',
            cursorclass = pymysql.cursors.DictCursor
           )
cur = conn.cursor()

#cur.execute('update ttt a set a.id2 = id2-100 where a.id1 = 1')
cur.execute('insert into  ttt values (1,100)')
# 休眠时间，以保证 session_BB 在调度时，session_AA 还未提交
time.sleep(10)
reslut=cur.execute('select * from ttt where id1 = 1')
msg = cur.fetchmany(reslut)
for output in msg:
    print(output['id2'])
    if output['id2'] < 0:
        conn.rollback()
        print('事务回退')
    else:
        conn.commit()
        print('事务提交')

cur.close()
conn.close()
