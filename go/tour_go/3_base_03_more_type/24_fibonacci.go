package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
	res := 0
	i := 0
	a := 0
	b := 1
	
	return func() int {
		if 0 == i {
			res = a
		} else if 1 == i {
			res = b
		} else {
			res = a +b
			a = b
			b = res
		}
	
		i++
	
		return res
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}

