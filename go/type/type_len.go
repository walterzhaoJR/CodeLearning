package main

import (
    "fmt"
    "unsafe"
)

func main(){

    a := 12
    fmt.Println("length of a:",unsafe.Sizeof(a))
    var b int = 20
    fmt.Println("length of b:",unsafe.Sizeof(b))
    var c int64 = 30000
    fmt.Println("length of c:",unsafe.Sizeof(c))
    var str string = "1234567890"
    fmt.Println("length of str:",unsafe.Sizeof(str))
    var r rune = 444
    fmt.Println("length of r:",unsafe.Sizeof(r))


}
