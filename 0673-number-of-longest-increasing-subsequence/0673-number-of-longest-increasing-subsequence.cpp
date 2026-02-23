class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1), count(n , 1);
        int current =1 , x =0;
        for(int i=0;i < n;i++){
            for(int k = 0; k<i;k++){
                if(nums[k] < nums[i] && dp[k] + 1> dp[i]){
                    dp[i] = dp[k] + 1; // switch
                    count[i] = count[k];
                }
                else if(nums[k] < nums[i] && dp[i] == 1 + dp[k]) {
                    count[i] = count[i] + count[k];
                }
            }
            current = max(current , dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i] == current) x+= count[i];
        }
        return x;
    }
};