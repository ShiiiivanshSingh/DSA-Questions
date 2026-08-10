class Solution {
public:
    int stoneGameVII(vector<int>& stones){
        int n = stones.size();
        vector prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int>> dp (n ,vector<int>(n,0));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len -1 < n; i++){
                int j = len - 1  + i;
                int leftleft  = prefix[j + 1] - prefix[i + 1],rightisleft= prefix[j] - prefix[i];
                int delLeft = leftleft - dp[i + 1][j];
                int delRight = rightisleft - dp[i][j - 1];

                dp[i][j] = max(delLeft, delRight);


            }
        }

    return dp[0][n-1];

        

        
    }
};