class Solution {
public:
    // jan hit me rakhi hai jankari
    // bawe hawabazzi puri khandhani
    // dl91 era
    
    bool possible(int n, vector<vector<int>>& grid){ //is MASK WORTH IT?
        for(auto &i: grid ){
            bool found =0;
            for(int j: i){
                if((j | n) == n){
                    found =1;
                    break;
                }
            }
            if(!found) return 0;
        }
        return 1;
    }
    // shisht ka phone aa gya hai myau
    int minimumOR(vector<vector<int>>& grid) {
        int ans =(1<<17); //ALL BITS ON
        ans--;
        for(int i = 16; i>=0;i--){
            int temp = ans^(1<<i);
            if(possible(temp, grid)) ans = temp;
        }
    return ans;
    }
    // janhit me rakhi hai jankari
    // hawabazi puri khandani 
    // dl91 era
};