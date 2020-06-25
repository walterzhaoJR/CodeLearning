###volatile
#### main.cpp
* (不使用volatile)如果wait函数在wake之前开始运行, 我可以先告诉你, wait函数将不会结束(-O2编译). 因为在线程1, 编译器的优化让wait函数只在一开始把flag的内存值读到寄存器一次, 后面一直用寄存器的值来跟count比较, 不再从内存读取flag的值.


#### volatile作用
* 1.被volatile修饰了的变量的操作不会被编译器优化掉(去除)
* 2.被volatile修饰的变量, 会强制编译器去每次方位这个变量都直接去访问内存对应存储位置(而不是读寄存器或者cpu cache)
* 3.多个被volatile修饰的变量之间的顺序, 不会被编译器优化调换指令顺序