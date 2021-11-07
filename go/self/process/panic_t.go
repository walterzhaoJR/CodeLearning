package main

import(
    "fmt"
    "math"
)

func contvertIntToInt16(x int) int16{
    if math.MinInt16 <= x && x <= math.MaxInt16{
        return int16(x)
    }

    panic(fmt.Sprint("%d is out of int16",x)) //手动出发panic
}

func main(){
    
    i := contvertIntToInt16(655567)
    fmt.Printf("%d",i)
}
