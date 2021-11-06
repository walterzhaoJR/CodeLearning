package main

import (
	// "fmt"
	"strings"
	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	count := make(map[string]int)
	
	WordArry := strings.Fields(s)
	
	for _, w := range WordArry {
		// fmt.Println(w)
		_, ok := count[w]
		if true == ok {
			count[w]++;
		} else {
			count[w] = 1
		}
	}
	
	return count
}

func main() {
	// fmt.Println(WordCount("i am walter"))
	wc.Test(WordCount)
	// fmt.Printf("Fields are: %q", strings.Fields("  foo bar  baz   "))
}

