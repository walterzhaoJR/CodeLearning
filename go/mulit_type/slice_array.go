package main

import(
    "fmt"
)

func main(){

    a := [...]int{1,2,3,4,5,6,7,8,9,0}
    fmt.Printf("array a  is %v,size:%d,cap:%d",a,len(a),cap(a))
    fmt.Printf("item in a:")
    for _,value := range(a){
        fmt.Printf("%d ",value)
    }
    
    fmt.Println()

    s1 := a[3:6]

    fmt.Printf("slice s1 is %v,size:%d,cap:%d",s1,len(s1),cap(s1))
    fmt.Printf("item in s1:")
    for _,value := range(s1){
        fmt.Printf("%d ",value)
    }

    fmt.Println()

    s1[0] = 999

    fmt.Printf("change item in s1:")
    for _,value := range(s1){
        fmt.Printf("%d ",value)
    }

    fmt.Println()

    s2 := make([]int,10,20)
    s2[7] = 9

    fmt.Printf("slice s2 is %v,size:%d,cap:%d",s2,len(s2),cap(s2))
    fmt.Printf("item in s2:")
    for _,value := range(s2){
        fmt.Printf("%d ",value)
    }

}
