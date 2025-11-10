class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));
        int moves = 0;
        
        while (dp[k][moves] < n) {
            moves++;
            for (int i = 1; i <= k; i++) {
                dp[i][moves] = dp[i-1][moves-1] + dp[i][moves-1] + 1;
            }
        }
        return moves;
    }
};