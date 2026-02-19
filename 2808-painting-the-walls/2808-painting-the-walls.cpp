class Solution {
public:
using ll = long long;

    int helper(int i , int left ,vector<int>& cost, vector<int>& time, vector<vector<int>>& dp, int n){
        if(left <= 0) return 0;
        if(i == n)  return INT_MAX;
        if(dp[i][left] != -1) return dp[i][left];
        
        // not pick
        int skip = helper( i + 1 , left , cost , time, dp, n);

        // pick 
        int newLeft = max(0  ,left - (1+ time[i]));
        int choose = helper(i+1 , newLeft , cost , time, dp, n);

        int temp = INT_MAX;
        if(choose != INT_MAX){
            temp = cost[i] + choose;
        }
        return dp[i][left] = min(skip , temp); 
    };

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int ans =0;
        int  n = cost.size();
        vector<vector<int>> dp;
        dp.assign(n, vector<int>(n+1, -1)); // min cost to paint
        // bool isBusy = 0;
        
        int x =helper(0 , n , cost , time, dp, n);
        return x;
    }
};