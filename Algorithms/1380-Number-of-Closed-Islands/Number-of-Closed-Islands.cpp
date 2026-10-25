class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j]) {
                    if (bfs(i, j, grid, visit)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    bool bfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<bool>>& visit) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = true;

        bool isClosed = true;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    isClosed = false;
                } else if (grid[nr][nc] == 0 && !visit[nr][nc]) {
                    visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return isClosed;
    }
};