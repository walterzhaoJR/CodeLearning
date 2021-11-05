package main

import (
	"fmt"
	"math"
)

func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

func calc(x, y int) bool {
	if x > y + 2 {
		return true
	}
	
	return false
}

func main() {
	fmt.Println(sqrt(2), sqrt(-4))
	fmt.Println(calc(1,2))
	fmt.Println(calc(4,2))
	fmt.Println(calc(5,2))
}

