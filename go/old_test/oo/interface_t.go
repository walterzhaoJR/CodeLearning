package main

import(
        "fmt"
      )

type Hume struct{
    name string
        age int
        pthone string
}

func (h Hume) sayHi(){
    fmt.Printf("hi i am hume\n")
} 

func (h Hume) sing(str string){
    fmt.Printf("lalala %s\n",str);
}

type student struct{
    Hume 
    school string
    loan float32
}

type employee struct{
    Hume
    company string
    money float32
}

//重载函数
func (emp employee) sayHi(){
    fmt.Printf("i am emp")
}

type Mem interface{
    sayHi()
    sing(str string)
}

func main(){
mike := student{Hume{"mike",22,"12345"},"bz",0.00}  
paul := student{Hume{"Paul", 26, "111-222-XXX"}, "Harvard", 100}
sam := employee{Hume{"Sam", 36, "444-222-XXX"}, "Golang Inc.", 1000}
Tom := employee{Hume{"Tom", 37, "222-444-XXX"}, "Things Ltd.", 5000}

     var i Mem
         i = mike
         fmt.Printf("this mike,student")
         i.sayHi()
         i.sing("zx")

         //i也能存储Employee
         i = Tom 
         fmt.Println("This is Tom, an Employee:")
         i.sayHi()
         i.sing("Born to be wild")
        
        fmt.Println("Let's use a slice of Men and see what happens")
        x := make([]Mem,3)
        x[0],x[1],x[2] = paul, sam, mike


        for _,value := range(x){
            value.sayHi()
        }
}
