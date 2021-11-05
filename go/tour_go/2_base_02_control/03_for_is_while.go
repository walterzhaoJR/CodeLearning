package main

import "fmt"


func test(x int) int {
	sub := 100
	i :=0 
	for sub > 0 {
		sub -= i
		i++
		fmt.Println(sub, i)
	}
	
	return i
}


func main() {
	sum := 1
	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)
	
	fmt.Println(test(100))
}

