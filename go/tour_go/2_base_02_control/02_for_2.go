package main

import "fmt"

func test() {
	sub := 1000
	i := 0
	for ; sub > 0; i++ {
		sub -= 10
		fmt.Println(sub, i)
	}
}

func main() {
	sum := 1
	for ; sum < 1000; {
		sum += sum
	}
	fmt.Println(sum)
	test()
}

