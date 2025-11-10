class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        dp[0][0][0] = 0;
        int ans= -1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = grid[i][j];
                int score, cost;
                if (val == 0) {
                    score = 0;
                    cost = 0;
                } else if (val == 1) {
                    score = 1;
                    cost = 1;
                } else {
                    score = 2;
                    cost = 1;
                }
                    for(int c=cost; c<=k; c++){
                        int best= -1;
                        if(i>0 && dp[i-1][j][c-cost]!=-1) best=max(best,dp[i-1][j][c-cost]);
                        if(j>0 && dp[i][j-1][c-cost]!=-1) best=max(best,dp[i][j-1][c-cost]);
                        if(i==0 && j==0 && c==0) best=0;
                        if(best!=-1) dp[i][j][c]=max(dp[i][j][c],best+score);
                    }
            }
        }
        
        for(int c=0;c<=k;c++) ans=max(ans,dp[m-1][n-1][c]);
        return ans;
    }
};




// class Solution {
// public:
//     int maxPathScore(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(n);
        
//         for(int i = 0 ; i< m ; i++){
//          if(i>0 && grid[i-1][j] == 0){
             
//          }   
//         }
//     }
    
// };
