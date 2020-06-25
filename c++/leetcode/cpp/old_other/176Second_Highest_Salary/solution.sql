select IFNULL ((select distinct Salary from Employee order by Salary desc limit 1 offset 1),NULL) as SecondHighestSalary;
//要注意如果没有要输出null的情况。所以使用ifnull()
