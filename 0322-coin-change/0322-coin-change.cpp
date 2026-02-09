class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int count =0;
       vector<int> dp(amount+1, amount + 1);
       dp[0] =0;

       for(int i=1;i<=amount;i++){
            for(int j : coins){
                if(j<=i){
                    dp[i] = min(dp[i] , dp[i-j] + 1);
                }
            }
       }
       if(dp[amount]> amount) return -1;
       return dp[amount]; 
    }
};