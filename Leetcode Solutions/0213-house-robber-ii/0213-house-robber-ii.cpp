class Solution {
public:
        int robb(vector<int>& nums , int left, int right) {
        int a =0;
        int b = 0;
        for(int i = left;i<= right ; i++){
            int loot = max(a , nums[i] + b);
            b = a ;
            a = loot;
        }
        return a;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n ==1) return nums[0];
        return max(robb(nums, 0,n-2), robb(nums , 1,n-1));
    }
};