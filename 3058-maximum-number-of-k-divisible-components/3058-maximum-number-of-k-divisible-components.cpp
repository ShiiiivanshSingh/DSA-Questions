class Solution {
public:
    int ans = 0;

    long long dfs(int u, int parent, vector<vector<int>>& g, vector<int>& values, int k) {
        long long s = values[u];

        for (int v : g[u]) {
            if (v == parent) continue;
            s += dfs(v, u, g, values, k);
        }

        if (s % k == 0) ans++;
        return s;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1, g, values, k);
        return ans;
    }
};
