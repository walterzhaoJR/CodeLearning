package main

import (
	"fmt"
	"math"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

func test(x, y int) bool {
	if x := x + y -3; 1 == x % 2 {
		return true
	}
	
	return false
}

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
	
	fmt.Println(test(1,2))
	fmt.Println(test(1,3))
}

