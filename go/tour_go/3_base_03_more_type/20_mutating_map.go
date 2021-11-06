package main

import "fmt"

func main() {
	m := make(map[string]int)

	m["Answer"] = 42
	fmt.Println("The value:", m["Answer"])

	m["Answer"] = 48
	fmt.Println("The value:", m["Answer"])

	delete(m, "Answer")
	fmt.Println("The value:", m["Answer"])

	v, ok := m["Answer"]
	fmt.Println("The value:", v, "Present?", ok)
	
	
	test := make(map[int]int)
	test[1] = 1
	test[2] = 3
	test[4] = 5
	
	elem, ok := test[3]
	fmt.Println(test, elem, ok)
}

