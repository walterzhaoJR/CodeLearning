#coding=utf-8
#function

'''

a="hello everyone"
print(len(a))
'''

'''
a="student"
print(a.split("u"))



def hello():
    print "hello funtion"


hello()

def myMax(a,b):
    if(a>b):
        print (a)
    elif a == b:
        print ("a = b:{0}".format(a));
    else:
        print (b)

myMax(1000,100)
'''

'''
def MyFun(a=1,b=2,c=3):
    print("{0} {1} {2}".format(a,b,c))


MyFun()
MyFun(10)
MyFun(20,30)
MyFun(100,1000,1000)
MyFun(a=9,c=8)
MyFun(c=999,b=99,a=9)#关键参数
MyFun(c=999,b=99,9)#关键参数，但是不能冲突，这个例子就冲突了
'''


'''
def returnValue(a):
    return a

def returnMore(a,b):
    return (a,b,a*b)

print (returnValue(10))
print (returnMore(10,5))
q,w,e = returnMore(11,12)
print ("{0},{1},{2}".format(q,w,e))
'''

#文档字符串
def testDoc(i):#文档字符串，一定要写在函数定义的下一行开始，使用三个冒号来注释
    '''
        argc:i int value
        return:i int value
        '''
    print (i)


print (testDoc.__doc__)#这中方式来显示文档字符串
help(testDoc)#这种形式也可以来显示文档字符串