package main

import "fmt"

type I interface {
	M()
}

type T struct {
	S string
}

// 此方法表示类型 T 实现了接口 I，但我们无需显式声明此事。
/*
func (t T) M() {
	fmt.Println(t.S)
}*/

type J struct {
	i int32
}

func (j J) M() {
	fmt.Println(j.i + 10)
}

func main() {
	//var i I = T{"hello"}
	//i.M()
	//j := 100
	var j J = J{100}
	j.M()
}

