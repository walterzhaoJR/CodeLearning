package main

import "fmt"

func swap(x, y string) (string, string) {
	return y, x
}

func calc(x, y int) (int, int) {
	return x + y, x -y
}

func main() {
	a, b := swap("hello", "world")
	x, y := calc(1, 2)
	
	fmt.Println(a, b)
	fmt.Println(x, y)
}