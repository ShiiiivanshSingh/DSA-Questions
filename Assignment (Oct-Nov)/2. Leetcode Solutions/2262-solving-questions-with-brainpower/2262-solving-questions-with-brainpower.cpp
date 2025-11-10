class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        int answer = 0;
        vector<long long> dp(n+1,0);
        for(int i= n - 1;i>=0;i--){
            long long myau = questions[i][0];
            long long meow = i + questions[i][1] + 1;
            if(meow < n) myau += dp[meow];
            long long skip = dp[i+1];
            dp[i] = max(myau, skip);
        }
        return dp[0];
    }
};