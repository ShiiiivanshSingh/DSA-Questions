// class Solution {
// public:
//     bool hasValidPath(vector<vector<char>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         if((m+n-1) % 2) return 0;
//         if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return 0;
// vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n,vector<bool>(m + n,
// 0)));
//         dp[0][0][1] = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;i<m;j++){
//                 for(int a =0;a<=m+n;a++){
//                     if(!dp[i][j][a]) continue;
//                     if(i+1<m){
//                         int new_a = a + (grid)
//                     }
//                 }
//             }
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2)  return 0;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return 0;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n,0)));
        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int a = 0; a <= m + n; a++) {
                    if (!dp[i][j][a])  continue;

                    if (i + 1 < m) {
                        int new_a = a;
                        if (grid[i + 1][j] == '(')  new_a++;
                        else   new_a--;
                        if (new_a >= 0)  dp[i + 1][j][new_a] = 1;
                    }

                    if (j + 1 < n) {
                        int new_a = a;

                        if (grid[i][j + 1] == '(')  new_a++;
                        else  new_a--;
                        if (new_a >= 0)  dp[i][j + 1][new_a] = 1;
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};
//         }

//     }
// };