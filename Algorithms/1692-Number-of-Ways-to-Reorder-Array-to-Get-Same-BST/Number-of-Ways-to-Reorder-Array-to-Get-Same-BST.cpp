class Solution {
    const int mod = 1e9 + 7;
    vector<vector<long long>> c;

    long long dfs(vector<int>& a) {
        int n = a.size();
        if(n < 3) return 1;

        vector<int> l, r;
        for(int i = 1; i < n; i++)
            if(a[i] < a[0]) l.push_back(a[i]);
            else r.push_back(a[i]);

        return c[n - 1][l.size()] * dfs(l) % mod * dfs(r) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        c.assign(n + 1, vector<long long>(n + 1, 1));

        for(int i = 2; i <= n; i++)
            for(int j = 1; j < i; j++)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;

        return (dfs(nums) - 1 + mod) % mod;
    }
};