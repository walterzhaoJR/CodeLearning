class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int total = 0;
        int size = nums.size();
        if(size < 1){
            return total;
        }
        
        int curr = 0;
        int index = 1;
        total = 1;
        while(index < size){
            curr = nums[index - 1];
            if(nums[index] != curr){
                nums[total] = nums[index];
                total++;
                
            }
            index++;
        }
        
        return total;   
    }
};
