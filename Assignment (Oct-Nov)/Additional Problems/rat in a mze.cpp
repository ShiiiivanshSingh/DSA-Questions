class Solution {
  public:
  void myau(int i , int j , vector<vector<int>>& maze , int n, vector<string> &ans, string move ,vector<vector<int>>& visited ){
      if( i == n -1 && j  == n-1) {
        ans.push_back(move);
        return; // final check
      }
      visited[i][j]=1;
      
      //up
      if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1){
        myau( i -1 , j , maze , n ,ans , move + "U" , visited);
      }
 
      //down
      if(i+1 <n && !visited[i+1][j] && maze[i+1][j] == 1){
        myau( i +1 , j , maze , n ,ans , move + "D" , visited);
      }
  
      //leffe
      if(j-1>=0 && !visited[i][j-1] && maze[i][j-1] == 1){
        myau( i  , j -1 , maze , n ,ans , move + "L" , visited);
      }
  
      //right
      if(j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1){
        myau( i , j+1 , maze , n ,ans , move + "R" , visited);
      }
      visited[i][j]=0;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
  
        
        int n = maze.size();
        // if(maze[0][0] ==0  || maze[ n-1][n-1] == 0) return; //entry exit blocked
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<string>  ans;
        
        if(maze[0][0]==1) myau(0,0,maze,n,ans,"",visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
