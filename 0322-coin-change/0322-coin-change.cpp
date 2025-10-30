class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n  = coins.size();
    vector<int> daa(amount+1 , amount+1);
    daa[0] = 0;


    for(int i=0;i<= amount;i++){
        for(int j: coins){
            if( j<=i){
                daa[i]  = min( daa[i - j ] + 1, daa[i]);
            }
        }
    }

    if(daa[amount] > amount) return -1;
    return daa[amount]; 
    }
};