class Solution {
public:
        vector<int> dp;
    int solve(int i , string &s){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];
        int dig_1 = solve(i+1,s), dig_2 = 0;
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))  dig_2 = solve(i + 2,s);
        return dp[i] = dig_1 + dig_2;
    }
    int numDecodings(string s) {
        dp.assign(s.size() , -1);
        return solve(0, s);
    }
};