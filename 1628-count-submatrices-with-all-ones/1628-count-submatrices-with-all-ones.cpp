class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> dp;
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> tower(cols,0);
        int ans =0 ;
        for(int i=0;i<rows;i++){

            for(int j =0;j< cols ; j++){
                if(mat[i][j] == 0) tower[j]= 0;
                else tower[j] +=1;
            }
    
            for(int p=0;p<cols;p++){
                int minH = tower[p];
                if( tower[p] == 0 ) continue;
                for(int a=p;a>=0;a--){ //left side traverse
                    if(tower[a] == 0) break; //stop left trav
                    minH = min(minH,tower[a]);
                    ans +=minH;
                    }
                }
        }
        return ans;
        }

};

            // for(int j =0;j< cols ; j++){
            //     // if(mat[i][j] == 1) count++;
            //     if(mat[i][j] == 1){
            //     if(i == 0 || i<rows-1 && mat[i+1][j] == 1) count++; //right
            //     if(i == rows-1 || i>0 && mat[i-1][j] == 1) count++; //left
            //     if(j == 0 || j>0 && mat[i][j-1] == 1) count++; //up
            //     if(j == cols-1 || j<cols-1 && mat[i][j+1] == 1) count++; //down
            //     }
            // }

                    // long long count = 1LL * rows * (rows + 1) / 2 * cols * (cols + 1) / 2; 
        // // int count = 0;
        // for(int i=0;i<rows;i++){
        //     for(int j =0;j< cols ; j++){
        //          if(mat[i][j] == 10) count--;

        //     }
        // }