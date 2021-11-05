package main

import "fmt"

func test(x int) int {
	sub := 0
	for i :=0; i < x; i++ {
		sub -= i
	}
	
	return sub
}

func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)
	
	fmt.Println(test(10))
}
