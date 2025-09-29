class Solution {
public:
    int ways(string s, int i,vector<int> &memo){
        if( i == s.size()) return 1;
      
        if(memo[i] != -1) return memo[i];
        
        if(s[i]=='0') return 0; 

        int final = ways(s , i+1,memo);

        if(i+1<s.size()){ 
            int ans = ((s[i] - '0')*10 + (s[i+1] - '0'));
            if(ans>=10 && ans<=26)        final += ways(s ,i+2, memo);
        }
    return memo[i] = final;
    }


    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return ways(s, 0, memo);
    }
};