package main

import (

    "fmt"
)

func swap1(x,y,p *int){

    if *x > *y {
    
        *x,*y = *y,*x 
    }

    *p = *x * *y
}

func swap2(x,y int)(int,int,int){

    if x>y{
    
        x,y = y,x
    }
    return x,y,x*y
}

func main(){

    i := 10
    j := 3
    res := 0
    swap1(&i,&j,&res)
    fmt.Println(i,j,res)

    a := 22
    b := 11
    r1,r2,r3 := swap2(a,b)
    fmt.Println(r1,r2,r3)
}
