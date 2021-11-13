package main

import (
	"fmt"
	"math"
)

type MyFloat float64
type MyInt int32

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func Int(I MyInt) int32 {
	return int32(I * 3)
}

func main() {
	f := MyFloat(-math.Sqrt2)
	fmt.Println(f.Abs())
	
	i := Int(100)
	fmt.Println(i)
}

