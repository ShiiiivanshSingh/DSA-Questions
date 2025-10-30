
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> achaa(2*n +1);
        vector<vector<int>> myau(n, vector<int>(n));

        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                achaa[i-j + n].push_back(grid[i][j]);
            }
        }
        for(int i=0 ; i< 2*n +1 ;i++){
            if (i<n){
                sort(achaa[i].begin(), achaa[i].end(), greater<int>());//ulta
            }
            else sort(achaa[i].begin(), achaa[i].end());
        }
            for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){    
                myau[i][j] = achaa[i-j + n].back(),  achaa[i-j + n].pop_back();
            }}
            return myau;
    }
};