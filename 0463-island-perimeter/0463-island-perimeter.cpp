class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row =  grid.size();
        int col = grid[0].size();
        int p =0 ;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
             if(grid[i][j] == 1){
                //dishao me udta jaise ubas
                if((i>0 && grid[i-1][j] == 0) || i ==0) p +=1; //upr
                if((i<row -1 && grid[i+1][j] == 0) || i ==row -1) p +=1; //neche
                if((j<col -1 && grid[i][j+1] == 0) || j ==col -1) p +=1; //r
                if((j>0 && grid[i][j-1] == 0) || j ==0) p +=1; //l
             }
        }

        }


        return p;
    }
};