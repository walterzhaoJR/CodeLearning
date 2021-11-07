package main

import (
"fmt"
"sync"
"time"
)

func main() {
	fmt.Println("test")

	var mutex sync.Mutex

	count := 0
	for r := 0; r < 50; r++ {
		go func() {
				mutex.Lock()
				defer mutex.Unlock()
				count += 1
			}()
		}

	time.Sleep(time.Second)
	fmt.Println(count)
}