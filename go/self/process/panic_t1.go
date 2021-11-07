package main

import(
    "fmt"
    "math"
)

func contvertIntToInt16(x int) int16{
    if math.MinInt16 <= x && x <= math.MaxInt16{
        return int16(x)
    }

    panic(fmt.Sprintf("%d is out of int16",x)) //手动出发panic
}


func int16FromInt(x int) (i int16,err error){
    defer func(){// 延迟执行匿名函数，并使用recover捕捉了panic，并将panic转换为了error
    
        if e := recover();e != nil{
            err = fmt.Errorf("%v",e)
        }
    }()

    i = contvertIntToInt16(x)
    return i,nil
}


func main(){
    
    if _,e := int16FromInt(655567); e != nil{
        fmt.Printf("%v",e)
    } else{
        fmt.Printf("no error")
    }
}
