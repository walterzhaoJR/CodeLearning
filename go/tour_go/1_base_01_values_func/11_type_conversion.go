package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int = 3, 4
	var f float64 = math.Sqrt(float64(x*x + y*y))
	var z uint = uint(f)
	fmt.Println(x, y, z)
	
	
	
	test := 100
	test1 := float64(test)
	test2 := uint(test1)
	fmt.Println(test, test1, test2)
}

