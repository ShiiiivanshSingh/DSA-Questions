class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(), l = INT_MAX, r = 0;
        vector<vector<pair<int,int>>> g(n);
        vector<int> deg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (!online[u] || !online[v]) continue;
            g[u].push_back({v, w});
            deg[v]++;
            l = min(l, w);
            r = max(r, w);
        }

        queue<int> q;
        for (int i = 1; i < n; i++)
            if (!deg[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &[v, w] : g[u])
                if (--deg[v] == 0 && v) q.push(v);
        }

        auto ok = [&](int x) {
            vector<long long> dp(n, LLONG_MAX / 2);
            vector<int> d = deg;
            queue<int> q;
            q.push(0);
            dp[0] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (u == n - 1) return dp[u] <= k;

                for (auto &[v, w] : g[u]) {
                    if (w >= x) dp[v] = min(dp[v], dp[u] + w);
                    if (--d[v] == 0) q.push(v);
                }
            }
            return false;
        };

        if (!ok(l)) return -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid)) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }
};