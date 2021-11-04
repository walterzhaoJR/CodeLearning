package main

import "fmt"

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}


func calc(x, y int) (a, b int) {
	a = x + y
	b = x - y
	return
}

func main() {
	fmt.Println(split(17))
	fmt.Println(calc(1,2))
}

