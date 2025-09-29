class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // if(amount == 0) return 0;
        // if(n == 1 && coins[i] < amount) return -1;

    vector<int> abc(amount+1,amount+1);
    abc[0] = 0;

        for(int i =1;i<= amount;i++){
            for(int j : coins){
                if(j <= i) {
                    abc[i] = min(abc[i] , abc[i-j]+1);
                }
            }
        }

        if(abc[amount] > amount)    return -1;
        return abc[amount]; 
    }
};