package main

import(
    "fmt"
)

func sum(a []int,result chan int){

    sum := 0
    for _, v := range a{
        sum += v
    }

    result <- sum
}

func main(){
    
    a := []int{2,3,4,5,1,-4,8,0,-3,-3,55,-41,32,80}
    result := make(chan int)
    go sum(a[:len(a)/2],result)
    go sum(a[len(a)/2:],result)
    x,y := <- result,<-result

    fmt.Println(x,y,x+y)

}
