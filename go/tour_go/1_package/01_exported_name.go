package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(math.Pi)
	// fmt.Println(math.pi) error pi unexported,Pi is exported
}