class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        using ll = long long;
        int n = grid[0].size();
        if(n == 1) return 0;

        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
        
        vector<vector<ll>> mx(n+1, vector<ll>(n+1, 0)); // max seen
        vector<vector<ll>> smx(n+1, vector<ll>(n+1, 0)); // suf max 
        vector<vector<ll>> pre(n, vector<ll>(n+1, 0));// prefix sum 

        for(int c = 0; c < n; c++)
            for(int r = 1; r <= n; r++)
                pre[c][r] = pre[c][r-1] + grid[r-1][c];

        for(int i = 1; i < n; i++){
            for(int ch = 0; ch <= n; ch++){
                for(int ph = 0; ph <= n; ph++){
                    if(ch <= ph){
                        ll ex = pre[i][ph] - pre[i][ch];
                        dp[i][ch][ph] = max(dp[i][ch][ph], smx[ph][0] + ex);
                    } else {
                        ll ex = pre[i-1][ch] - pre[i-1][ph];
                        dp[i][ch][ph] = max({dp[i][ch][ph], smx[ph][ch], mx[ph][ch] + ex});
                    }
                }
            }

            for(int ch = 0; ch <= n; ch++){
                mx[ch][0] = dp[i][ch][0];
                for(int ph = 1; ph <= n; ph++){
                    ll pen = (ph > ch) ? (pre[i][ph] - pre[i][ch]) : 0;
                    mx[ch][ph] = max(mx[ch][ph-1], dp[i][ch][ph] - pen);
                }

                smx[ch][n] = dp[i][ch][n];
                for(int ph = n-1; ph >= 0; ph--)
                    smx[ch][ph] = max(smx[ch][ph+1], dp[i][ch][ph]);
            }
        }

        ll ans = 0;
        for(int k = 0; k <= n; k++)
            ans = max({ans, dp[n-1][n][k], dp[n-1][0][k]});

        return ans;
    }
};