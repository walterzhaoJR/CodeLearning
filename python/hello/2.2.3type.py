#列表

student = ['zx','dd','xr','myn']
print(student[2])

student[2] = 'walter' #列表的元素可以修改
print(student[2])

#元组
math = (1,2,3,4,5)
print (math[3])
print(math[0])


#math[2] = 0  #元组中的元素不能修改
print(math[2])

#set:集合
#集合的作用就是消除重复元素和建立关系

a = set("aabbcdefghijk")
b = set("fghkli")

print(a&b)
print(a | b)
print(a - b)

new = set(a)#去掉重复的元素
print(new)


#字典：保存键值对
k={'a':1,'b':2,'c':3}
print(k['a'])

k['d'] = 4#添加元素
print(k)

k['a'] = 5#修改元素

print(k)