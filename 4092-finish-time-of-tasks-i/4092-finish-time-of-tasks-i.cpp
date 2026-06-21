class Solution {
public:
    long long dfs(int u, vector<vector<int>>& g, vector<int>& t) {
        if (g[u].empty()) return t[u];

        long long mn = LLONG_MAX, mx = 0;

        for (int v : g[u]) {
            long long x = dfs(v, g, t);
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return mx + mx - mn + t[u];
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& t) {
        vector<vector<int>> g(n);

        for (auto &e : edges)
            g[e[0]].push_back(e[1]);

        return dfs(0, g, t);
    }
};