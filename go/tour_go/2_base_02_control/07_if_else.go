package main

import (
	"fmt"
	"math"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		fmt.Printf("%g >= %g\n", v, lim)
	}
	// 这里开始就不能使用 v 了
	return lim
}


func test(x, y int) bool {
	if x < y {
		return true
	} else {
		return false
	}
	
	return false
}

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
	
	fmt.Println(test(1,2))
	fmt.Println(test(3,2))
}

