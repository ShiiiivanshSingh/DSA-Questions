class Solution {
public:
    bool isSafe(int a , int b, int n){
        if(a<n && b<n && a>=0 && b>=0) return 1;
        else return 0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int,int>> moves = {
            {1,2},{2,1},{2,-1},{1,-2},
            {-1,-2},{-2,-1},{-2,1},{-1,2}
        };

        double ans =0.00;
        vector<vector<double>> dp(n, vector<double>(n, 0.0)); //probs
        dp[row][column] = 1.0;
        for(int steps =0; steps<k;steps++){
            vector<vector<double>> new_dp(n, vector<double>(n, 0.0));
            for(int row =0 ;row<n;row++){
                for(int col =0 ;col<n;col++){
                    if(dp[row][col] >0) {
                        for(auto &i : moves){
                            int new_row = row +i.first;
                            int new_col =col + i.second;

                            if(isSafe(new_row, new_col, n)){
                                new_dp[new_row][new_col] += dp[row][col] /8.0;
                            }
                        }
                    }
                }
            }
            dp =new_dp;
        }


        for(int row =0 ;row<n;row++){
                for(int col =0 ;col<n;col++){
                    ans += dp[row][col];
            }
        }
        return ans;
    }
};