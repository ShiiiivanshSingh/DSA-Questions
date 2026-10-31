class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int M = 1e9 + 7;
        int n = grid[0].size(), left = 1;

        for (int i = 0; i < grid.size(); i++, left = 0)

            for (int j = 0; j < n; j++) {

                int top = 0;
                if (i) 
                    top = grid[i - 1][j];
                if (grid[i][j])     
                    grid[i][j] = left, left = top;
                else 
                    grid[i][j] = left = (left + top) % M;
            }
            
        return grid.back().back();
    }
};