class Solution {
public:
// void cherry(int n  , int  i , int j , vector<vector<int>>& grid , int &ans ,int current){
//     if(i ==n -1 && j == n-1) {
//         ans  = max(ans , current + grid[i][j]);
//         return;
//     }
//     if(grid[i][j] == -1 ) return;
//     int temp = grid[i][j];
                  
//     grid[i][j] =0;

//     if(i + 1< n && grid[i+1][j] != -1 ) cherry(n , i+1, j , grid , ans , current + temp);

//     if(j + 1< n && grid[i][j+1] != -1 ) cherry(n , i , j+1 , grid , ans , current + temp);
    
//     grid[i][j] = temp;
// }


 int cherry(int i,int j,int p,vector<vector<int>>& grid,vector<vector<vector<int>>>& vass){
    int n= grid.size();
    int q= i+j-p;
    if(i>=n || j>=n || p>=n || q>=n || grid[i][j]==-1|| grid[p][q]==-1)return INT_MIN;
    if(i==n-1&&j==n-1) return grid[i][j];
    if(vass[i][j][p]!=-1) return vass[i][j][p];
    int ans=grid[i][j];
    if(i!=p || j!=q )ans+=grid[p][q];
    ans += max({cherry(i+1,j,p+1,grid,vass),cherry(i,j+1,p,grid,vass),
                cherry(i+1,j,p,grid,vass),cherry(i,j+1,p+1,grid,vass)});
    return vass[i][j][p]=ans;
 
}

int cherryPickup(vector<vector<int>>& grid) {
    int n  = grid.size();
    vector<vector<vector<int>>> vass(n,vector<vector<int>>(n,vector<int>(n,-1)));
    return max(0,cherry(0,0,0,grid,vass));
    }
};