package main

import "fmt"

func main() {
	{
		v := 42 // 修改这里！
		fmt.Printf("v is of type %T\n", v)
	}
	
	{
		v := 42.1
		fmt.Printf("v is od type %T\n", v)
	}
	
	{
		v := true
		fmt.Printf("v is od type %T\n", v)
	}
	
	{
		v := "test"
		fmt.Printf("v is od type %T\n", v)
	}
}

