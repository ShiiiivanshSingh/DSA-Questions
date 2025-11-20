class Solution {
public:
int bfs(queue<pair<int , int>>&q , int fresh, vector<vector<int>>& grid, int N, int M){
    int mins = 0;
    vector<vector<int>> dir = {{0,1}, {1,0} ,{0,-1},{-1,0}};

    while(!q.empty()){
         auto[r , c] = q.front();
         q.pop();

        if(r == -1 && c == -1){
            if(!q.empty()){
                mins++;
                q.push({-1, -1});
            }
            continue;
        }

        for(int i=0 ;i<4; i++){
                int newR = r + dir[i][0];
                int newC = c + dir[i][1];
            
            if(newR >=0 && newC >=0 && newR < N && newC < M && grid[newR][newC] ==1){  
                grid[newR][newC] = 2; 
                fresh--;
                q.push({newR , newC});
                } 
            }
        }   
        
        return fresh > 0 ? -1 : mins;
}
    int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
        int fresh = 0;
        queue<pair<int , int>>q;
        for(int i =0;i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            } else if(grid[i][j] == 1) {
                fresh++;
            } else {
                continue;
                }
            }
        }
        q.push({-1 , -1});
        return bfs(q , fresh ,grid , n ,m);
    }
};