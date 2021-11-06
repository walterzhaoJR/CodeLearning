package main

import "fmt"

func main() {
	names := [4]string{
		"John",
		"Paul",
		"George",
		"Ringo",
	}
	fmt.Println(names)

	a := names[0:2]
	b := names[1:3]
	fmt.Println(a, b)

	b[0] = "XXX"
	fmt.Println(a, b)
	fmt.Println(names)
	
	
	test := [5]int {1,2,3,4,5}
	
	test1 := test[1:4]
	test2 := test[2:5]
	fmt.Println(test1, test2)
	test1[1] = 9
	fmt.Println(test, test1, test2)
}

