package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

type Int struct {
	i int32
}

func (i Int) Test(a int32) int32 {
	return i.i * a
}

func (i Int) My(a int32) {
	i.i = a
}

func main() {
	v := Vertex{3, 4}
	v.Scale(10)
	fmt.Println(v.Abs())
	
	i := Int{100}
	i.My(10)
	fmt.Println(i.Test(5))
}

