class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
       // hmmmm
       // hmmm (a + b) % k = smethang
       // myau OwO 

        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int meow = 0;

        for(int i : nums){
            int rem = i % k;
            for(int r = 0; r< k;r++){
                int prev = (r - rem + k) % k;
                dp[r][rem] = max(dp[r][rem], dp[r][prev] + 1);
                meow = max(meow,dp[r][rem]);
            }
        }
    return meow;
    }
};