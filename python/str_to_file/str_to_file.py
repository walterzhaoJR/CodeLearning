#coding=utf-8

import random
import string
import time
import datetime



def create_str():
    str = ''.join(random.sample(string.ascii_letters + string.digits, 50))
    return (str+"\n")


def wriet_file(file_path,num):
    f = open(file_path, "ab+")
    for i in range(num):
        f.write(create_str())



if __name__ == "__main__":
    wriet_file("/data/log/test.log",1000)