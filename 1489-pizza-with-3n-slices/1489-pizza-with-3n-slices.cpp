class Solution {
public:
int dp[505][170];

    int helper(int start , int end, vector<int>& slices, int n){
        if(n ==0 || start > end) return 0;
        if(dp[start][n] != -1) return dp[start][n];
        int take = slices[start] + helper(start + 2, end , slices, n -1);
        int not_take = helper(start + 1, end , slices, n);

        return dp[start][n] = max(take, not_take);
    }
    int solve(vector<int>& slices, int start, int end){
        memset(dp, -1, sizeof(dp));
        return helper(start, end, slices, slices.size()/3);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        // int a = helper(0 , n-2 , slices , n/3);
       // int b = helper(1 , n-1 , slices , n/3);
        // int n = slices.size();
        return max(
            solve(slices, 0, n-2),
            solve(slices, 1, n-1)
        );
    }
};