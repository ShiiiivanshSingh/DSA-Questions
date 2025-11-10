class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        for(int  i =0;i< nums.size() ; i++){
            if(nums[s] != nums[i]) s++;
            nums[s] = nums[i];
        }
        return s+1;
    }
};