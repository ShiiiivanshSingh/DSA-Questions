class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total =0;
        for(int i: nums) total+=i;

        if(abs(target)> total) return 0;
        if ((target + total) % 2 != 0) return 0;  
        
        int x = (total +target) /2;

        vector<int> dp(x+1, 0);
        dp[0] =1;
        for(int i: nums){
            for(int j=x; j>=i;j--)  dp[j] = dp[j] + dp[j -i];
        }
        return dp[x];
    }
};