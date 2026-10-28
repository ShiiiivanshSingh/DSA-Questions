// using ll = long long;

// class Solution {
// public:
//     const ll mod = 1e9 + 7;
//     ll abc(ll a, ll b){
//         if(a == 0) return 1;
//         ll x = abc(b * b % mod, b/2);
//         if(b & 1) x = x * a % mod;
//         return res;
//     }
//     int minCost(vector<vector<int>>& grid) {
//         ll c =1;
//         for(int i=0;i<k)
//     }
// };
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int B = 1024;

        vector<vector<bitset<B>>> dp(m, vector<bitset<B>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int v = grid[i][j];
                bitset<B> from;
                if (i > 0) from |= dp[i - 1][j];
                if (j > 0) from |= dp[i][j - 1];

                for (int x = 0; x < B; x++) {
                    if (from[x]) dp[i][j][x ^ v] = 1;
                }
            }
        }

        for (int x = 0; x < B; x++) {
            if (dp[m - 1][n - 1][x]) return x;
        }
        return -1; // unreachable
    }
};