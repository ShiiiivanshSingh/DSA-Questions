class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();
        unordered_map<int, vector<int>> diagonal;

        for(int  i = 0;i < rows;i++){
            for(int  j = 0;j < cols;j++){
                diagonal[i - j].push_back(mat[i][j]);
            }
        }
        
        for(auto &i : diagonal){
            sort(i.second.rbegin(), i.second.rend());
        }

        for(int  i = 0;i < rows;i++){
            for(int  j = 0;j < cols;j++){
                mat[i][j]  = diagonal[i  - j ].back();
                diagonal[i - j].pop_back();
            }    
        }
        return mat;

    }
};