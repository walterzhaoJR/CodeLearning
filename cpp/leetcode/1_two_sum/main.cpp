class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> num_index;//保存num和index信息
        std::vector<int> result;
        
        result.push_back(0);
        result.push_back(0);
        
        
        int other_num = 0;
        for(int i=0;i<nums.size();i++){
            other_num = target - nums[i];
            auto iter = num_index.find(other_num);
            if(iter == num_index.end()){//没有找见目标减去第一元素的值
                num_index.insert(std::make_pair(nums[i],i));//将当前的这个值和位置保存
            }
            
            else{//找到之后
                int other_index = iter->second;
                if(i < other_index){
                    result[0] = i;
                    result[1] = other_index;
                }
                else{
                    result[0] = other_index;
                    result[1] = i;
                }
                return result;
            } 
        }
        return result;
    }
};
