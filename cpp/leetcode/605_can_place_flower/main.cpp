// https://leetcode-cn.com/problems/can-place-flowers
#include <iostream>
#include <vector>

using namespace std;
class Solution {
/*
首先这里我用的是连跳两格的方法，因为如果遇到1,那么下一格子一定是0，这是毋庸置疑的（规则限定），所以如果遇到最后一个格子，或者下个格子不是1，果断填充
*/
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; i+=2) {
            if (0 == flowerbed[i]) { // 如果当前为空地, 如果是最后一格或者下一格为空
                if (i == size - 1 || flowerbed[i + 1] == 0) {
                    n--;
                } else {
                    i++;
                }
            }
        }

        return n <= 0;
    }
};

int main()
{
    Solution s;
    // [0] n = 0
    {
        std::vector<int> v = {0};
        cout << "1 "<< s.canPlaceFlowers(v, 0) << endl;
    }

    // [0] n = 1
    {
        std::vector<int> v = {0};
        cout << "1 " << s.canPlaceFlowers(v, 1) << endl;
    }

    // [0, 0] n = 1
    {
        std::vector<int> v = {0, 0};
        cout << "1 " << s.canPlaceFlowers(v, 1) << endl;
    }

    // [0, 0] n = 2
    {
        std::vector<int> v = {0, 0};
        cout << "0 " << s.canPlaceFlowers(v, 2) << endl;
    }

    // [1,0,0,0,1], n = 1
    {
        std::vector<int> v = {1,0,0,0,1};
        cout << "1 " << s.canPlaceFlowers(v, 1) << endl;
    }

    // [1,0,0,0,1], n = 2
    {
        std::vector<int> v = {1,0,0,0,1};
        cout << "0 " << s.canPlaceFlowers(v, 2) << endl;
    }

    // [1,0,0,0,1,0], n = 2
    {
        std::vector<int> v = {1,0,0,0,1,0};
        cout << "0 " << s.canPlaceFlowers(v, 2) << endl;
    }

    // [1,0,0,0,1,0,0], n = 2
    {
        std::vector<int> v = {1,0,0,0,1,0,0};
        cout << "1 " << s.canPlaceFlowers(v, 2) << endl;
    }

      // [1,0,1,0,1,0], n = 1
    {
        std::vector<int> v = {1,0,1,0,1,0};
        cout << "0 " << s.canPlaceFlowers(v, 1) << endl;
    }

    // [0,1,0] n = 1
    {
        std::vector<int> v = {0,1,0};
        cout << "0 " << s.canPlaceFlowers(v, 1) << endl;
    }

    //[0,0,1,0,1] n = 1
    {
        std::vector<int> v = {0,0,1,0,1};
        cout << "1 " << s.canPlaceFlowers(v, 1) << endl;
    }
}