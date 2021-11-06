package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

type Point struct {
	X float64
	Y float64
}

func main() {
	fmt.Println(Vertex{1, 2})
	fmt.Println(Point{1.1, 2.2})
}

