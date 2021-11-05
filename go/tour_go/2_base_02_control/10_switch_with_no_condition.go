package main

import (
	"fmt"
	"time"
)



func test() {
	index := 2
	switch {
	case index == 1:
		fmt.Println(1)
	case index == 2:
		fmt.Println(2)
	case index == 3:
		fmt.Println(3)
	
	}
}

func main() {
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
	
	test()
}

