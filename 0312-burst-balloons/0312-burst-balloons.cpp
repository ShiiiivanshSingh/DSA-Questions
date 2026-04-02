class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n+2, 1);
        for(int i=0;i<n;i++) num[i+1] = nums[i];
        n+=2; // new len
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int l = 2; l < n ; l++){ // windown size
            for(int i=0;i + l < n; i++){
                int pos  = i + l;
                for(int j= i+ 1;j<pos ; j++){
                    dp[i][pos] = max(dp[i][pos] , dp[i][j] + dp[j][pos] + (num[i]* num[pos] * num[j]));
                }
            }
        }
    
    return dp[0][n-1];
    }
};