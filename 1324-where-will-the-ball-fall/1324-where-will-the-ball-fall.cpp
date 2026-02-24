class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int currentCol = i;
            for(int j =0 ; j<m;j++){
                int nextCol = currentCol + grid[j][currentCol];
                if(nextCol <0 || nextCol >=n || grid[j][currentCol] != grid[j][nextCol] ){
                    currentCol = -1;
                    break; // block
                }
                currentCol = nextCol;
            }
            ans.push_back(currentCol);
        }

        return ans;
    }
};