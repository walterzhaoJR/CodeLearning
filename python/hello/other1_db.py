#coding = utf-8


import pymysql
import random


'''
db = pymysql.connect(host='127.0.0.1',port=4000,user='root',db='test')

cursor = db.cursor()

cursor.execute("select age from test;")

data = cursor.fetchone()

print(data)
if data[0] > 10:
    print("data > 10")
else:
    print("data < 10")
'''



class myDB():

    #def __init__(self,ip,port,passwd,user,db,num):
    def __init__(self, ip, port, user, db, num):
        self.ip = ip
        self.port = port
        self.user = user
        self.db = db
        #self.passwd = passwd
        self.num = num
        #self.dbTest = pymysql.connect(host=self.ip,port=self.port,passwd = self.passwd,user=self.user,db=self.db)
        self.dbTest = pymysql.connect(host=self.ip, port=self.port, user=self.user, db=self.db)
        self.cursor = self.dbTest.cursor()


    def execSql(self,count):#count为sql执行的次数
        for i in range(0,count):
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
                    print(data)

                except:
                    self.dbTest.rollback()
                    print("rollback")

            i = i + 1
            print("R:{}".format(str(i)))







def main():
    #db = myDB(ip = '127.0.0.1',port = 3306,passwd = "158776zx",user= 'root',db = 'test',num = 2000)
    db = myDB(ip='127.0.0.1', port=4000, user='root', db='test', num=50)

    db.execSql(1)


if __name__ == '__main__':
    main()