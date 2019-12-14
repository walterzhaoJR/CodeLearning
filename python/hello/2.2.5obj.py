#python的对象
#python中一切皆对象

#python对象如果需要持久性存储，就需要序列化，这个过程叫pickle（腌制）

import pickle


#dumps 序列化对象
lista = ["mingyue","jishi","you"]
listb = pickle.dumps(lista)

#print(listb)


#loads 反序列化对象
listc = pickle.loads(listb)

print(listc)


#将对象保存到外部文件中，使用dump和load
group1 = ("bajiu","wen","qingtian")
f1 = open('test.txt','wb')
pickle.dump(group1,f1,True)
f1.close()

f2 = open('test.txt','rb')
group2 = pickle.load(f2)
print((group2))
f2.close()

