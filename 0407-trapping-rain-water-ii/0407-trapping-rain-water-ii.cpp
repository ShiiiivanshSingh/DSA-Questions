class Solution {
public:
    typedef pair<int, pair<int,int>> a;
    vector<vector<int>> direction = {{0,-1} ,{0,1} , {-1,0} ,{1,0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();  
    int n = heightMap[0].size();  
    
    priority_queue<a, vector<a> , greater<>> boundary;
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for(int row = 0;row<m; row++){
        for(int col :{0,n-1}){
            boundary.push({heightMap[row][col], {row ,col}});
            visited[row][col]  =1;
        }
    }
    for(int col = 0;col<n; col++){
        for(int row :{0,m-1}){
            boundary.push({heightMap[row][col], {row ,col}});
            visited[row][col]  =1;
        }
    }


    int water = 0;

        while(!boundary.empty()){
            a meow = boundary.top();
            boundary.pop();

            int i= meow.second.first; 
            int j= meow.second.second; 
            int height = meow.first; 
            
            for(vector<int>&dir : direction){
                int i_  = i + dir[0];
                int j_  = j + dir[1];

                if(i_>=0 && i_< m  && j_>=0 && j_<n && !visited[i_][j_]){
                    water += max(height -heightMap[i_][j_] , 0);

                    boundary.push({max(height, heightMap[i_][j_]) , {i_,j_}});
                    visited[i_][j_]  =1;
                }
            }
        }
    return water;
    }
};