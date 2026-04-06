class Solution {
public:
vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int euclid(int a , int b){
        int total =0;
        total = (a * a) + b * b;
        return total;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obobsacles) {
    
        vector<int> current = {0,0};
        int x=0, y=0, pos = 0 ,euc_dis =0;
        set<pair<int,int>> obs;
        for(auto &k : obobsacles) obs.insert({k[0], k[1]});

        for(int i : commands){
            if(i == -1){
                pos = (pos + 1) % 4;
                continue;
            }   // right turn  
            else if( i == -2){
                pos = (pos + 3) % 4;  
                continue;
            } // left turn 
            else{
                for(int k = 0; k < i; k++){
                    int new_x = x + dir[pos][0];
                    int new_y = y + dir[pos][1];

                    if(obs.count( {new_x, new_y} ))
                        break;

                    x = new_x;
                    y = new_y;
                    
                    euc_dis = max(euc_dis, euclid(x,y));
                }
            }
        }
            return euc_dis;
        
    }
};