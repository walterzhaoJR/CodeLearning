// https://leetcode-cn.com/problems/candy/
/*
你会不会认为存在比较关系的贪心策略一定需要排序或是选择？虽然这一
道题也是运用贪心策略，但我们只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；
先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历，
分配的糖果就可以满足题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一
侧的大小关系。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 0;
        int size = ratings.size();

        if (size < 2) {
            count = 1;
        } else {
            std::vector<int> num(size, 1);
            // 从左向右
            for (int i = 1; i < size; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    num[i] = num[i - 1] + 1;
                }
            }

            // 从右向左
            for (int i = size -1; i > 0; i--) {
                if (ratings[i - 1] > ratings[i]) {
                    num[i - 1] = std::max(num[i - 1], num[i] + 1);
                }
            }

            count = std::accumulate(num.begin(), num.end(), 0); // sum
        }

        return count;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> ratings = {1};
        cout << "num:" << s.candy(ratings) << endl;
    }

    {
        std::vector<int> ratings = {2};
        cout << "num:" << s.candy(ratings) << endl;
    }

    {
        std::vector<int> ratings = {1, 2};
        cout << "num:" << s.candy(ratings) << endl;
    }

    {
        std::vector<int> ratings = {1, 2, 3};
        cout << "num:" << s.candy(ratings) << endl;
    }

    {
        std::vector<int> ratings = {1, 0, 2};
        cout << "num:" << s.candy(ratings) << endl;
    }

    {
        std::vector<int> ratings = {1, 2, 2};
        cout << "num:" << s.candy(ratings) << endl;
    }

    return 0;
}
