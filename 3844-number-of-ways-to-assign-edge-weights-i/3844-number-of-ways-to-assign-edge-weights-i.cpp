class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    int pow(int x, int y) {
        int ans = 1;
        while (y) {
            if (y & 1)    ans = 1LL * ans * x % mod;
            x = 1LL * x * x % mod;
            y >>= 1;
        }
        return ans;
    }



    int dfs(vector<vector<int>>& g, int u, int p) {
        int d = 0;
        for (int v : g[u]) {
            if (v != p)
                d = max(d, dfs(g, v, u) + 1);
        }

        return d;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return pow(2, dfs(g, 1, 0) - 1);
    }
};