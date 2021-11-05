package main

import "fmt"


func test() {
	defer fmt.Println("zhao")
	fmt.Println("walter")
}

func main() {
	defer fmt.Println("world")
	
	test()
	
	fmt.Println("hello")
}

