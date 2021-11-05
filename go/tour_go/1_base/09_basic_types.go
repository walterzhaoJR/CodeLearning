package main

import (
	"fmt"
	"math/cmplx"
)

var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

var (
	Test bool = true
	MaxInt2 int32 = 1 << 16 -1
	My complex128 = cmplx.Sqrt(1 + 10i)
)

func main() {
	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)
	
	fmt.Printf("type %T value:%v\n", Test, Test)
	fmt.Printf("type %T value:%v\n", MaxInt2, MaxInt2)
	fmt.Printf("type %T value:%v\n", My, My)
}

