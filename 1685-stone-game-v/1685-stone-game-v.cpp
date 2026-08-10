class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int left = 0 , right = n -1, alice =0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i <n; i++)  
            prefix[i+1] = prefix[i] + stoneValue[i];

        for (int i = 0; i < n; i++)  
            dp[i][i] = 0;


        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;
                        
                for (int mid = i; mid < j; mid++) {
                    int leftSum = prefix[mid + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[mid + 1];

                // if(i == j) dp[i][j] = 0;
                    if(leftSum > rightSum) dp[i][j] = max(dp[i][j], rightSum + dp[mid + 1][j]);
                    else if(leftSum < rightSum) dp[i][j] = max(dp[i][j] , leftSum + dp[i][mid]);
                    else dp[i][j] =  max({dp[i][j], leftSum + dp[i][mid], rightSum + dp[mid + 1][j] });
                    
                    }
                }
            }
        return dp[0][n-1];
    }
};