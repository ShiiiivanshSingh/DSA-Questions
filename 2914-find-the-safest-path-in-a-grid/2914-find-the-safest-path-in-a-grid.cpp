class Solution {
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n = g.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j])
                    q.push({i, j}), g[i][j] = 0;
                else
                    g[i][j] = -1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && g[nx][ny] == -1) {
                    g[nx][ny] = g[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<vector<int>> pq;
        pq.push({g[0][0], 0, 0});
        g[0][0] = -1;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int sf = cur[0], x = cur[1], y = cur[2];

            if (x == n - 1 && y == n - 1)
                return sf;

            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && g[nx][ny] != -1) {
                    pq.push({min(sf, g[nx][ny]), nx, ny});
                    g[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};