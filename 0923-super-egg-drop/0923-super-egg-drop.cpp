class Solution {
public:
    int superEggDrop(int k, int n) {
        int op = 0;
        vector<long long> dp(k + 1, 0);
        while (dp[k]< n){
            op++;
            for (int i = k; i >= 1; i--) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }

        return op;
    }
};