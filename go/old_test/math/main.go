package main

import "fmt"

func add(a int,b int) int{
	return a+b;
}


func sub(a int,b int)int{
	return a-b;
}


func main(){
	fmt.Println("a+b:",add(10,11))
	fmt.Println("a-b:",sub(100,20))
}
