package main

import(
    "fmt"
)

func main(){

   test := make(map[string]string)
   test["name"] = "walter"
   test["age"] = "23"
   test["country"] = "China"
   test["job"] = "ccomputer program engine"

   for key := range(test){
   
    fmt.Printf("test key:%s\n",key)
   }

   delete(test,"job")
   test["name"] = "myn"

   v,found := test["job"]
   fmt.Printf("job is exist %t,job is %s\n",found,v)
    
    fmt.Printf("Traverse all key/value of test:\n")
    for k,v := range(test){
        fmt.Printf("k:%s v:%s\n",k,v)
    }
}
