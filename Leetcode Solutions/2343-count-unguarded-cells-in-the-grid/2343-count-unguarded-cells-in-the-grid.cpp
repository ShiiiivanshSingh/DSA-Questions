struct pair_hash {
    size_t operator() (const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        unordered_set<pair<int, int>, pair_hash> walls_set;
        unordered_set<pair<int, int>, pair_hash> guards_set;

        for (auto& it: walls) {
            int i = it[0], j = it[1];
            walls_set.insert({i, j});
        }
        for (auto& it: guards) {
            int i = it[0], j = it[1];
            guards_set.insert({i, j});
        }

        int cells_cnt = 0;
        for (auto& it: guards) {
            int i = it[0], j = it[1];

            // up
            int up_i = i;
            while (up_i-1 >= 0 && !walls_set.count({up_i-1, j}) && !guards_set.count({up_i-1, j})) {
                vis[up_i-1][j] == 0 ? cells_cnt++ : cells_cnt;
                up_i--;
                vis[up_i][j] = 1;
            }
            // down
            int down_i = i;
            while (down_i+1 < m && !walls_set.count({down_i+1, j}) && !guards_set.count({down_i+1, j})) {
                vis[down_i+1][j] == 0 ? cells_cnt++ : cells_cnt;
                down_i++;
                vis[down_i][j] = 1;
            }
            // left
            int left_j = j;
            while (left_j-1 >= 0 && !walls_set.count({i, left_j-1}) && !guards_set.count({i, left_j-1})) {
                vis[i][left_j-1] == 0 ? cells_cnt++ : cells_cnt;
                left_j--;
                vis[i][left_j] = 1;
            }
            // right
            int right_j = j;
            while (right_j+1 < n && !walls_set.count({i, right_j+1}) && !guards_set.count({i, right_j+1})) {
                vis[i][right_j+1] == 0 ? cells_cnt++ : cells_cnt;
                right_j++;
                vis[i][right_j] = 1;
            }
        }    

        return m * n - guards.size() - walls.size() - cells_cnt; 
    }
};