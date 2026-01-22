class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
     vector<vector<int>> ans;   

        for(int i = 0 ; i<land.size();i++){
            for(int j = 0 ; j<land[0].size();j++){
                if( land[i][j] == 1){
                    int x = i;
                    int y = j;

                while(x+1 < land.size() && land[x+1][j] == 1 ) x++;
                while(y+1 < land[0].size() && land[i][y+1] == 1 ) y++;  

                for(int a1 = i; a1<= x; a1++){
                    for(int a2 = j ; a2 <=y ;a2++){
                        land[a1][a2] = 0;
                    }
                }
                ans.push_back({i , j ,x ,y});
                }
            }
        }
    return ans;
    }
};