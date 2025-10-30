class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void myau(int r, int c, vector<vector<int>>& h, vector<vector<int>>& ocean){
            ocean[r][c] = 1;
            
            for(auto &i : dir){
                int x = r + i[0];
                int y = c + i[1];

                if(x < 0 || x >=m || y <0 || y>=n) continue;
                if(ocean[x][y] || h[x][y] <  h[r][c]) continue;

                myau(x,y,h,ocean);
            }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         m = heights.size();
         n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0));
        vector<vector<int>> result;


        for(int i=0;i<m;i++){
            myau(i,0 , heights , pacific);
            myau(i, n-1, heights, atlantic);
        }

        for(int i=0;i<n;i++){
            myau(0,i , heights , pacific);
            myau(m-1, i , heights, atlantic);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }
    return result;
    }
};