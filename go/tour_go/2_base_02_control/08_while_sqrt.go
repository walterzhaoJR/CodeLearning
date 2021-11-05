package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	z := 1.0
	for i :=0; i < 10; i++ {
		z -= (z*z - x) / (2*z)
		fmt.Println(z)
	}
	
	return z
}

func Sqrt2(x float64) float64 {
	z := 1.0
	last := 2.0
	for i :=0; math.Abs(last - z) > 0.000000000000001; i++ {
		last = z
		z -= (z*z - x) / (2*z)
		fmt.Println(z, last, math.Abs(last - z))
	}
	
	return z
}

func main() {
	fmt.Println(Sqrt2(2))
}

