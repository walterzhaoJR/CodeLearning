// https://leetcode-cn.com/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int g_size = g.size();
        int s_size = s.size();

        int g_index = 0;
        int s_index = 0;

        int count = 0;

        while(g_index < g_size && s_index < s_size) {
            cout << "g_index:" << g_index << " g:" << g[g_index] << " s_index:" << s_index << " s:" << s[s_index] << endl;
            if (s[s_index] >= g[g_index]) {
                s_index++;
                g_index++;
                count++;
            } else {
                s_index++;
            }
            
        }

        return count;
    }
};

int main()
{
    Solution s;

    std::vector<int> g1 = {1,2,3};
    std::vector<int> s1 = {1,2,3};

    cout << "test1:\n" << s.findContentChildren(g1, s1) << endl;

    std::vector<int> g2 = {1,2,3};
    std::vector<int> s2 = {1,1};

    cout << "test2:\n" << s.findContentChildren(g2, s2) << endl;

    std::vector<int> g3 = {1,2,};
    std::vector<int> s3 = {1,2,3};

    cout << "test3:\n" << s.findContentChildren(g3, s3) << endl;

    return 0;
}
