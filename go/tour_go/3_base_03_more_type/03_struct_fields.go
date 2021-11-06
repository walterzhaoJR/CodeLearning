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
	v := Vertex{1, 2}
	v.X = 4
	fmt.Println(v.X)
	
	p := Point{1.1, 2.2}
	p.X = 3.3
	p.Y = 4.4
	fmt.Println(p)
	fmt.Println(p.Y)
}

