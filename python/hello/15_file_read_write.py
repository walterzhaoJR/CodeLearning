#coding=utf-8
#file read write


'''

text = 'Hello everyone.I am Walterzhao'

f = open("/Users/walter/Desktop/my_file_test",'ab+')
f.write(bytes(text,encoding="utf-8"))#因为python3是bytes-like的
f.close

'''


'''
append_text = 'This a new line,append a new line to old text'

f = open("/Users/walter/Desktop/my_file_test",'ab+')
f.write(bytes(append_text,encoding="utf-8"))#因为python3是bytes-like的
f.close

'''


read_file = open("/Users/walter/Desktop/my_file_test",'r')
content = read_file.read()
print(content)
