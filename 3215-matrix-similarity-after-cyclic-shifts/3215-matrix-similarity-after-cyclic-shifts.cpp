class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = k % n;
        for(int i =0;i<m;i++){
            for(int j=0; j<n;j++){
                int var = (j + k) % n;
                if(mat[i][j] != mat[i][var]) return 0;
            }
        }
        return 1;
    }
};