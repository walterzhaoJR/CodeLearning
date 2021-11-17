package main

import (
	"fmt"
	"math"
)

type I interface {
	M()
}

type T struct {
	S string
}

func (t *T) M() {
	fmt.Println(t.S)
}

type F float64

func (f F) M() {
	fmt.Println(f)
}

type J int32

func (j J) M() {
	fmt.Println(j+100)
}

func main() {
	var i I

	i = &T{"Hello"}
	describe(i)
	i.M()

	i = F(math.Pi)
	describe(i)
	i.M()
	
	i = J(20)
	describe(i)
	i.M()
	
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}

