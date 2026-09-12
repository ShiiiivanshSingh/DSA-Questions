class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& a) {
        int n = a.size();
        vector<tuple<int, int, int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({a[i][0], a[i][1], a[i][2], i});
        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return get<1>(a) < get<1>(b); });

        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> id(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++) {
            auto [l, r, w, x] = v[i];
            int k = lower_bound(v.begin(), v.begin() + i, l,
                                [](auto& t, int x) { return get<1>(t) < x; }) -
                    v.begin();

            for (int j = 1; j < 5; j++) {
                long long s = dp[k][j - 1] + w;
                if (dp[i][j] > s) {
                    dp[i + 1][j] = dp[i][j];
                    id[i + 1][j] = id[i][j];
                } else {
                    vector<int> z = id[k][j - 1];
                    z.push_back(x);
                    sort(z.begin(), z.end());
                    if (dp[i][j] == s && id[i][j] < z)
                        z = id[i][j];
                    dp[i + 1][j] = s;
                    id[i + 1][j] = z;
                }
            }
        }
        return id[n][4];
    }
};