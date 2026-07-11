class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    void dfs(int u, int &v, int &e) {
        vis[u] = 1;
        v++;
        e += g[u].size();

        for (int x : g[u])
            if (!vis[x]) dfs(x, v, e);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        g.assign(n, {});
        vis.assign(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int v = 0, e = 0;
            dfs(i, v, e);

            if (v * (v - 1) == e) ans++;
        }

        return ans;
    }
};