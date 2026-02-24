class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        vector<int> ans;
        for (int i=0; i< n ;i++){
            int row = 0, col = i;
            bool isStuck =0; // currently freeflowing
            while(col  < n && row < m){
                if(grid[row][col] == 1 && col != n-1 && grid[row][col + 1] != -1){
                    row++;
                    col++;
                } else if(grid[row][col] == -1 && col !=0 && grid[row][col - 1] != 1 ){
                    row++;
                    col--;
                } else {
                    isStuck =1;
                    break; // unretrievable
                }
            }
            if(isStuck) ans.push_back(-1);
            else ans.push_back(col);
        }
        return ans;
    }
};