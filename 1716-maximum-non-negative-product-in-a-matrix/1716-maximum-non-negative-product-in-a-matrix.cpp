using ll = long long;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<ll>> max1(n, vector<ll>(m));
        vector<vector<ll>> min1(n, vector<ll>(m));
        
        max1[0][0] = min1[0][0] = grid[0][0];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                
                ll a = LLONG_MIN;
                ll b = LLONG_MAX;
                
                if(i > 0){
                    a = max(a, max1[i-1][j]);
                    b = min(b, min1[i-1][j]);
                }
                if(j > 0){
                    a = max(a, max1[i][j-1]);
                    b = min(b, min1[i][j-1]);
                }
                
                if(grid[i][j] >= 0){
                    max1[i][j] = a * grid[i][j];
                    min1[i][j] = b * grid[i][j];
                } else {
                    max1[i][j] = b * grid[i][j];
                    min1[i][j] = a * grid[i][j];
                }
            }
        }
        
        ll res = max1[n-1][m-1];
        if(res < 0) return -1;
        return res % 1000000007;
    }
};