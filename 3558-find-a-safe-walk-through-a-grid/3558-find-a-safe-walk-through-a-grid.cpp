class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> q;
        vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
        q.push_front({0,0});
        dis[0][0] = grid[0][0];

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop_front();

            if (x == m - 1 && y == n - 1) return 1;

            for (auto [dx,dy] : d) {
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int w = dis[x][y] + grid[nx][ny];
                if (w >= health || w >= dis[nx][ny]) continue;
                dis[nx][ny] = w;

                if (grid[nx][ny]) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }

        return 0;
    }
};