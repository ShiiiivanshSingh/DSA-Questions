class Solution {
public:

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool is_valid(vector<vector<int>>& grid, int right, int c,int t, vector<vector<bool>>& visited){
        if(right<0 || right>= grid.size() || c<0 || c>=grid[0].size() || visited[right][c] || grid[right][c] > t){
            return false;
        }
        visited[right][c] = true;

        if(right == grid.size()-1 && c == grid.size()-1){
            return true;
        }

        for(auto& d : dirs){
            int nr = right+d.first;
            int nc = c+d.second;

            if(is_valid(grid, nr, nc, t, visited)){
                return true;

            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = n*n-1;

        int res = 0;
        while(left<=right){
            int mid = left+(right-left)/2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if(is_valid(grid, 0, 0, mid, visited)){
                res = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
};