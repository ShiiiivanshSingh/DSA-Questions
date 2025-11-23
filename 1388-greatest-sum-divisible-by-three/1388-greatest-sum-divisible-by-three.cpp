class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      
        vector<int> dp(3, 0);

        for (int num : nums) {
   
            vector<int> arr = dp;

            for (int sum : arr) {
                int newSum = sum + num;
                int rem = newSum % 3;
                dp[rem] = max(dp[rem], newSum);
            }
        }

        return dp[0];
    }
};
