文件描述符

1.6.2

3.

    echo "hello" > temp   这个操作会先清空文件，再将字符串写入
    echo "walter" >> temp 这个操作不会清空文件，而是在文件末尾追加

4.

- 当一个命令执行结束后可以用echo $?来查询执行的情况，0位正常，非0位异常情况
- 将错误重定向到文件 ls + 2> err_out.log
- 再将输出重定向到另外一个文件：ls + 2>err_out.log 1> temp.log
- 还可以将stderr转换成stdout，使得这两个重定向到一个文件中：ls + 2>&1 temp.log
- 可以将以一些无用的信息直接重定向到/dev/null中
- 可以使用tee做这样的操作：既把信息重定向到文件中，有可以在显示出来 cmd | tee file
  - ls -l | tee out.log | cat -n  #cat -n是从stdin中接受数据并加上行号
  - 默认情况下 tee 会覆盖源文件，但是 -a参数可以追加信息 ls -a | tee -a out.log | cat -n

1.6.4

- stdin的读取的输入可以多种方式接收数据
  - cat file | cmd
  - cmd1 | cmd
- 使用stdin从文件中读取数据 cmd < cfile   : cat < file

* 可以使用exec 创建文件描述符
* exec 3 < test.log 创建一个文件描述符3，并读取文件
* 使用这个文件描述符  cat &3

* 创建一个文件描述符用于写入： exec 4 > out.log
* echo "heloo" > &4

