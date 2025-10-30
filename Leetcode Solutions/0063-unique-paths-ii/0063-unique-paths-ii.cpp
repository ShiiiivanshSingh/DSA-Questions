class Solution {
public:
    int okhai(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&uwu){
        if(m<0 || n<0) return 0;
        if(grid[m][n]==1) return 0;
        if(m==0&&n==0) return 1;

        if(uwu[m][n]!=-1)return uwu[m][n];



        int up = okhai(m-1,n,grid,uwu);
        int left = okhai(m,n-1,grid,uwu);
        return uwu[m][n]= up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>&obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size() ;


       vector<vector<int>>uwu(m,vector<int>(n,-1));

        return okhai(m-1,n-1,obstacleGrid,uwu);
    }
};
