package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	z := make([][]uint8, dy)
	
	for y := range z {
		z[y] = make([]uint8, dx)
		for x := range z[y] {
			z[y][x] = uint8((x + y) / 2)
		}
	}
	
	return z
}

func main() {
	pic.Show(Pic)
}

