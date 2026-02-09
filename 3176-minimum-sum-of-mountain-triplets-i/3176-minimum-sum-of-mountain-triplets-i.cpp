class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans= INT_MAX;
        vector<int> leftside(n , nums[0]);
        for(int i=1;i<n;i++) leftside[i] = min(leftside[i-1], nums[i]);

        int rightside = nums[n-1];
        for(int i=n-2;i>0;i--) {
            if(nums[i] > leftside[i-1] && nums[i] > rightside){
                ans = min(ans, rightside + nums[i] + leftside[i-1]);
            }
            rightside = min(nums[i] , rightside);
        }


        return ans == INT_MAX ? -1 : ans;
    }
};