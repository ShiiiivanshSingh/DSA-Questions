
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        bool up = true;

        while (row < m && col < n) {
            result.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {
                    row++;
                    up = !up;
                } else if (row == 0) {
                    col++;
                    up = !up;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    up = !up;
                } else if (col == 0) {
                    row++;
                    up = !up;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};