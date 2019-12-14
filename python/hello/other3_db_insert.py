#coding = utf-8


import pymysql

# 打开数据库连接
db = pymysql.connect(host="127.0.0.1", user="root", port = 4000,db="test", charset='utf8' )
db = pymysql.connect(host="127.0.0.1", user="root", port = 3306,passwd = '158776zx',db="test", charset='utf8' )

# 使用cursor()方法获取操作游标
cursor = db.cursor()

# SQL 插入语句
sql = """INSERT INTO test1(age)
         VALUES (2000)"""



for i in range(0,10000):
    try:
        # 执行sql语句
        cursor.execute(sql)
        # 提交到数据库执行
        db.commit()
        print("commit")
    except:
        # Rollback in case there is any error
        db.rollback()
        print("rollback")

    i = i+1

# 关闭数据库连接
db.close()





