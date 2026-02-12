class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary;
        for(auto i: wordDict){
            dictionary.insert(i);
        }
        int n =s.size();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;

        for(int  i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]){
                    if(dictionary.find(s.substr(j , i - j)) != dictionary.end()){

                        dp[i] =1;
                        break;
                    }
                } 
            }
        }
    return dp[n];
    }
};