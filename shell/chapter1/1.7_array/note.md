# 1.7 数组和关联数组

* 借助索引将多个独立数据存储为一个集合
* 普通数组用int作为index
* 关联数组用string做index

## 1.7.1

* 定义数组： array_var = {0 1 2 2 3}这些值会分布在以0开始的索引上

* 或者这样定义：

  ``` linux
  array_var[0] = "test"
  array_var[1] = "hrlloo"
  array[3] = "walter"
  ```


## 1.7.2输出：

  * echo ${array_var[0]}，

  * 或者 index = 5;echo ${array_var[5]}

  * 以清单形式打印：

   ```linux
  echo ${array_var[*]}
  echo ${array_var[@]}
   ```

  * 打印数组长度 echo ${#array_var[*]}



## 1.7.3关联数组

* 首先需要将一个变量声明为关联数组 declare -A ass_array

* 其次添加元素：

  * ass_array=([index1] = val1 [index2] = val2)

  * 或者：

    ```linux
    ass_array[index1] = val1 
    ass_array[index2] = val2
    ```

* 输出 echo ${ass_array[index1]}

* 列出数组的索引：

  * 获取索引列表：echo ${!ass_array[*]} 或者 echi ${!ass_array[@]}

* 对于普通数组也可以这样用
