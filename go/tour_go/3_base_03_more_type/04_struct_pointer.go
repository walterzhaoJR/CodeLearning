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
	p := &v
	p.X = 1e9
	fmt.Println(v)
	
	p1 := Point{1.1, 2.2}
	pPtr := &p1
	(*pPtr).X = 1.2
	pPtr.Y = 2.3
	fmt.Println(*pPtr)
}

