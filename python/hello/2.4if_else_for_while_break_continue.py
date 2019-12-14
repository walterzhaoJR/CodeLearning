#coding=utf-8
#Python流程控制

'''
for i in range(0,3):
    i = 0
    print i
    i += 1
    print i
'''


'''
source = 100

if(source > 50):
    print("good")
else:
    print("bad")
'''

'''
i = 0
while(i<10):
   print("{0}".format(i),i*i)
   i+=1
'''

'''
#分支结构
source = 100

if(100 == source):
    print("very good")
elif (source > 80):
    print("good")
elif(source > 60):
    print("so so")
else:
    print("bad")
'''

'''
#循环结构
for i in range(1,10,2):
    print(i)

for i in [1,2,3,6,7,8,3,4]:
    print(i)
    
for i in (1,2,1,2,1,2):
    print(i)
'''

i = 0
while(True):
    if(i > 10):
        print("break")
        break

    if(0 == i%4):
        print("continue")
        i += 1
        continue
    else:
        print(i)
        i += 1













