package main

import "fmt"

func main() {
	s := []int{2, 3, 5, 7, 11, 13}

	s = s[1:4]
	fmt.Println(s)

	s = s[:2]
	fmt.Println(s)

	s = s[1:]
	fmt.Println(s)
	
	test := []int{1,2,3,4,5}
	test1 := test[0:]
	test2 := test[:5]
	test3 := test[:]
	fmt.Println(test, test1, test2, test3)
}

