class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uq = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[uq] != nums[i])
                uq++;
            nums[uq] = nums[i];
        }
        return  uq+1;
    }
};