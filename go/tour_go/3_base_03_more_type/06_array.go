package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)

	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(primes)
	
	
	var str[3]string
	str[0] = "name:"
	str[1] = "walter"
	str[2] = "zhao"
	fmt.Println(str)
	
	test := [3]int{1,2,3}
	fmt.Println(test)
}

