class Solution {
public:
const int INF = 1e9;

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        if ((n - 1) % (k - 1) != 0)
            return -1; // intrger chk
        vector<int> prefix(n+1);
        for(int i= 0 ; i < n;i++) prefix[i+1] = prefix[i] + stones[i];

        vector<vector<vector<int>>> dp( n, vector< vector <int>> ( n, vector<int>(k+1, INF)));
        for(int i = 0 ; i< n ; i++){
            dp[i][i][1] = 0; // no cost
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int m = 2; m <= min(len , k); m++) {
                for (int mid = i; mid < j; mid += k - 1){

                    if (dp[i][mid][1] == INF || dp[mid + 1][j][m - 1] == INF) continue;
                    dp[i][j][m] = min(dp[i][j][m], dp[i][mid][1] + dp[mid + 1][j][m - 1]); }
            } 
          
    //         if (dp[i][j][k] != INF)
    // dp[i][j][1] = dp[i][j][k] +( prefix[j + 1] - prefix[i] );
    //     }
        if ((len - 1) % (k - 1) == 0 && dp[i][j][k] != INF)
        dp[i][j][1] = dp[i][j][k] + prefix[j + 1] - prefix[i];
          } 
        }
        return dp[0][n - 1][1];
    }
};