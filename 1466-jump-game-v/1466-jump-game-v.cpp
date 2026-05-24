class Solution {
public:


    vector<int> dp;

    int dfs(vector<int>& a, int i, int d) {
        if (dp[i] != -1) return dp[i];
        dp[i] = 1;
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (a[j] >= a[i]) break;
            dp[i] = max(dp[i], 1 + dfs(a, j, d));
        }
        





        for (int j = i + 1; j <= min((int)a.size() - 1, i + d); j++) {
            if (a[j] >= a[i]) break;
            dp[i] = max(dp[i], 1 + dfs(a, j, d));


        }

        return dp[i];
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size() , ans = 1;   
        dp.assign(n, -1);
        for (int i = 0; i < n; i++) ans = max(ans, dfs(arr, i, d));
        return ans;
    }



        
};