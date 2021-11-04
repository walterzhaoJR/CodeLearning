package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func sub(x int, y int) int {
	return x - y
}


func main() {
	fmt.Println(sub(100, 23))
	fmt.Println(add(1,3))
}