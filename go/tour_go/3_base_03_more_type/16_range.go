package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}
	
	
	test := []int{1,2,3,4,5,6,7,8,9,0}
	for i, e := range test {
		fmt.Println(i, e)
	}
}

