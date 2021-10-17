// https://leetcode-cn.com/problems/non-overlapping-intervals/
/*
在选择要保留区间时，区间的结尾十分重要：选择的区间结尾越小，余留给其它区间的空间
就越大，就越能保留更多的区间。因此，我们采取的贪心策略为，优先保留结尾小且不相交的区
间。
具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选
择的区间不重叠的区间。我们这里使用 C++ 的 Lambda，结合 std::sort() 函数进行自定义排
序
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // lambda 表达式 自定义排序
        sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int min = intervals[0][0];
        int max = intervals[0][1];

        int index = 1;
        int size = intervals.size();

        while(index < size) {
            if (intervals[index][0] >= max) {
                max = intervals[index][1];
            } else {
                count ++;
            }
            index ++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    
    {
        std::vector<std::vector<int>> intervals = {{1,2}, {1,2}, {1,2}};
        cout << "num:" << s.eraseOverlapIntervals(intervals) << endl;
    }
    
    {
        std::vector<std::vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
        cout << "num:" << s.eraseOverlapIntervals(intervals) << endl;
    }

    {
        std::vector<std::vector<int>> intervals = {{1,2}, {2,3}};
        cout << "num:" << s.eraseOverlapIntervals(intervals) << endl;
    }

    {
        std::vector<std::vector<int>> intervals = {{1,100}, {11,22}, {1,11}, {2,12}};
        cout << "num:" << s.eraseOverlapIntervals(intervals) << endl;
    }

    {
        std::vector<std::vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
        cout << "num:" << s.eraseOverlapIntervals(intervals) << endl;
    }
    
    
    
    return 0;
}
