class Solution {
public:
    vector<int> dp, a;
    int n;

    int dfs(int i) {
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        int sum = 0, ans = INT_MIN;
        for (int j = i; j < min(n, i + 3); j++) {
            sum += a[j];
            ans = max(ans, sum - dfs(j + 1));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        a = stoneValue;
        n = a.size();
        dp.assign(n, INT_MIN);

        int x = dfs(0);

        if (x > 0) return "Alice";
        if (x < 0) return "Bob";
        return "Tie";
    }
};