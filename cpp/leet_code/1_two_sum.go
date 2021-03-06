package main

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
import "fmt"

func twoSum(nums []int, target int) []int {
	prev := 0
	tail := prev + 1
	len := len(nums)
	var array = []int{prev,tail}

	for prev < tail && tail < len {
		if target == nums[prev] + nums[tail] {
			break
		} else {
			tail++
		}

		if tail == len {
			prev++
			tail = prev + 1
		}
	}

	array[0] = prev
	array[1] = tail

	return array
}

func main() {
	var nums = []int{2, 7, 11, 15,1}
	var target int = 8
	fmt.Print(twoSum(nums, target))
}
