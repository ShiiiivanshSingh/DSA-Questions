class Solution {
public:
using ll = long long;
static const long long kill = LLONG_MIN;
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();
        ll  ans =kill;
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(3, kill)));
        // if(coins[0][0] < 0) dp[0][0][1] = 0; // -1 bullet
        // else  dp[0][0][0] = coins[0][0];

        dp[0][0][0] = coins[0][0];          // don't neutralize
        if(coins[0][0] < 0) 
            dp[0][0][1] = 0;                // neutralize
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int b =0;b<=2;b++){ // b here is the no. of bullets
                    if(dp[i][j][b] ==  kill) continue;

                    if (n>j+1) {
                        int val = coins[i][j + 1];

                        dp[i][j + 1][b] = max(dp[i][j + 1][b],
                                              dp[i][j][b] + val);

                        if (val < 0 && b < 2) {
                            dp[i][j + 1][b + 1] = max(dp[i][j + 1][b + 1],
                                                      dp[i][j][b]);
                        }
                    }

                    if (i + 1 < m) {
                        int val = coins[i + 1][j];

                        dp[i + 1][j][b] = max(dp[i + 1][j][b],
                                              dp[i][j][b] + val);

                        if (val < 0 && b < 2) {
                            dp[i + 1][j][b + 1] = max(dp[i + 1][j][b + 1],
                                                      dp[i][j][b]);
                        }
                    }

                }
            }
        }
        for (int b = 0; b <= 2; b++) ans = max(ans, dp[m - 1][n - 1][b]);
        // if(m ==4 && n == 4)            
       //cout << dp[3][3][1];
        return (int)ans;
    }
};


                    // if(n > j+ 1){
                    //     ll next_bal = coins[i][j+1];
                    //     for(int ammo = b; ammo<=2;ammo++){
                    //        // if (dp[i][j][ammo] == kill) continue;
                    //         ll new_bal = dp[i][j][ammo];
                    //         if(next_bal <0 && ammo <2) {
                    //             new_bal = max(new_bal, dp[i][j][ammo]);
                    //         } else {
                    //             new_bal = max(new_bal, next_bal + dp[i][j][ammo]);
                    //         }
                    //         dp[i][j+1][b] = max(dp[i][j+1][b], new_bal);
                    //     }
                    // }
        
        

        // for (int j = 1; j < n; j++) 
        //     dp[0][j] = dp[0][j - 1] + coins[0][j];
        
        // for (int i = 1; i < m; i++) 
        //     dp[i][0] = dp[i - 1][0] + coins[i][0];


        
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {

        //         if(bullets >0 && coins[i][j] < 0){
        //             bullets--;
        //             coins[i][j] =0;
        //         }
        //         dp[i][j] = coins[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        //     }
        // }

        // return dp[m - 1][n - 1];
        // // dp[0][0] = coins[0][0];
        // // for(int i=m;i>0;i--){
        // //     for(int j=n;j>0;j--){
        // //         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        // //     }
        // // }
        // // return dp[0][0];
                    // if(m > i + 1){
                    //     ll next_bal = coins[i+1][j];
                    //     for(int ammo = b; ammo<=2;ammo++){
                    //        // if (dp[i][j][ammo] == kill) continue;
                    //         ll new_bal = dp[i][j][ammo];
                    //         if(next_bal < 0 && ammo < 2  ){
                    //             new_bal = max(new_bal, dp[i][j][ammo]);
                    //         } else {
                    //             new_bal = max(new_bal, next_bal + dp[i][j][ammo]);
                    //         }
                    //         dp[i+1][j][b] = max(dp[i+1][j][b], new_bal);
                    //     }
                    // }