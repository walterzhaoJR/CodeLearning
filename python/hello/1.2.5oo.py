
class Hello:

    def __init__(self,name):
        self._name = name


    def say(self):
        print("Hello {0}".format(self._name))



class Hi(Hello):#继承


    def __init__(self,name):
        Hello.__init__(self,name)#调用父类的构造方法
    def sayHi(self):
        print("say hi {0}".format(self._name))



h = Hello("walter")
h.say()


h1 = Hi("zx")
h1.sayHi()
