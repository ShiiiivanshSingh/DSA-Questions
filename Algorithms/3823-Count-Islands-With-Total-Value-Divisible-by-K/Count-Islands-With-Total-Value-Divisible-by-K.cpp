class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++)
                if (grid[r][c]) count += dfs(grid, r, c) % k == 0;
        return count;
    }

private:
    long long dfs(vector<vector<int>>& g, int r, int c) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || !g[r][c]) return 0;
        long long s = g[r][c];
        g[r][c] = 0;
        return s + dfs(g, r + 1, c) + dfs(g, r - 1, c) + dfs(g, r, c + 1) + dfs(g, r, c - 1);
    }
};