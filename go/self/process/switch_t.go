package main

import(
        "fmt"
      )


func classcheck(item ...interface{}){

    for i,x := range item{
        switch x := x.(type){//影子变量
            
            case bool:
                fmt.Printf("param #%d is a bool, value: %t\n", i, x)
            case float64:
                fmt.Printf("param #%d is a float64, value: %f\n", i, x)
            case int, int8, int16, int32, int64:
                fmt.Printf("param #%d is a int, value: %d\n", i, x)
            case uint, uint8, uint16, uint32, uint64:
                fmt.Printf("param #%d is a uint, value: %d\n", i, x)
            case nil:
                fmt.Printf("param #%d is a nil\n", i)
            case string:
                fmt.Printf("param #%d is a string, value: %s\n", i, x)
            default:
                fmt.Printf("param #%d's type is unknow\n", i)
        }
    }
}

func main(){
    classcheck(5,-12.34,"walter",nil,true,complex(2,1))
}
