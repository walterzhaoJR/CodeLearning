package main

import "fmt"

func main() {
	primes := [6]int{2, 3, 5, 7, 11, 13}

	var s []int = primes[1:4]
	fmt.Println(s)
	
	
	test := [5]int{1,2,3,4,5}
	
	var a []int = test[2:5]
	fmt.Println(test, a)
}

