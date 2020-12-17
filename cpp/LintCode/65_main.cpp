/*
两个排序的数组A和B分别含有m和n个数，找到两个排序数组的中位数，要求时间复杂度应为O(log (m+n))。

样例
样例1

输入:
A = [1,2,3,4,5,6]
B = [2,3,4,5]
输出: 3.5
样例2

输入:
A = [1,2,3]
B = [4,5]
输出: 3
挑战
时间复杂度为O(log n)

说明
中位数的定义：

这里的中位数等同于数学定义里的中位数。
中位数是排序后数组的中间值。
如果有数组中有n个数且n是奇数，则中位数为A[(n-1)/2]A[(n−1)/2]。
如果有数组中有n个数且n是偶数，则中位数为 (A[n / 2] + A[n / 2 + 1]) / 2(A[n/2]+A[n/2+1])/2.
比如：数组A=[1,2,3]的中位数是2，数组A=[1,19]的中位数是10。
*/

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int num1_size = nums1.size();
      int num2_size = nums2.size();
      std::vector<int> temp;
      double res = 0.0;

      if (0 == num1_size && 0 == num2_size) {
        cout << "vec size error";
      } else if (0 == num1_size) {
        res = findMedianSortedArray(nums2);
      } else if (0 == num2_size) {
        res = findMedianSortedArray(nums1);
      } else {
        int index_1 = 0, index_2 = 0, index = 0;
        int target_index = (num1_size + num2_size) / 2;

        while(index <= target_index) {
          if (nums1[index_1] <= nums2[index_2]) {
            if (index_1 < num1_size) {
              temp.emplace_back(nums1[index_1]);
              index_1++;
            } else {
              temp.emplace_back(nums2[index_2]); 
              index_2++;
            }
          } else {
            if (index_2 < num2_size) {
              temp.emplace_back(nums2[index_2]); 
              index_2++;
            } else {
              temp.emplace_back(nums1[index_1]);
              index_1++;
            }
          }

          index++;
        }
        
        int temp_size = temp.size();
        if (0 == (num1_size + num2_size) % 2) {
          res = (temp[temp_size -1 ] + temp[temp_size - 2]) / 2.0;
        } else {
          res =  temp[temp_size - 1];
        }
      }
      
      return res;
    }

    double findMedianSortedArray(const vector<int>& nums) {
      double res = 0;
      int size = nums.size();
      int index  = size / 2;

      if (0 == size % 2) {
        return (nums[index - 1] + nums[index]) / 2.0;
      } else {
        return nums[index];
      }

      return res;
    }
};

int main()
{
  Solution s;
  
  std::vector<int> num11;
  std::vector<int> num12 = {2};
  cout << "TEST ==> expect:2 res:" << s.findMedianSortedArrays(num11, num12) << endl;
  
  std::vector<int> num21 = {1};
  std::vector<int> num22;
  cout << "TEST ==> expect:1 res:" << s.findMedianSortedArrays(num21, num22) << endl;

  std::vector<int> num31 = {1, 2};
  std::vector<int> num32 = {3, 4};
  cout << "TEST ==> expect:2.5 res:" << s.findMedianSortedArrays(num31, num32) << endl;

  std::vector<int> num41 = {1, 2, 3};
  std::vector<int> num42 = {3, 4};
  cout << "TEST ==> expect:3 res:" << s.findMedianSortedArrays(num41, num42) << endl;

  std::vector<int> num51 = {1, 2, 3};
  std::vector<int> num52 = {9};
  cout << "TEST ==> expect:2.5 res:" << s.findMedianSortedArrays(num51, num52) << endl;
  
  std::vector<int> num61 = {1, 7, 9, 11, 11, 11, 13};
  std::vector<int> num62 = {9, 12, 12, 14};
  cout << "TEST ==> expect:11 res:" << s.findMedianSortedArrays(num61, num62) << endl;
  
  return 0;
}
