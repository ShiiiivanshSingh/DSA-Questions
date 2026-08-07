class Solution {
public:
  vector<vector<vector<int>>> dp;

    int solve(int index, int zerosLeft, int onesLeft, vector<string>& strs) {
        if (index == strs.size())   return 0;
          if (dp[index][zerosLeft][onesLeft] != -1)   return dp[index][zerosLeft][onesLeft];

        string curr= strs[index];
        int zero =0, one =0;
        for(char c: curr){
            if (c == '0')  zero++;
            if (c == '1')  one++;
        }
        int skip = solve(index + 1, zerosLeft, onesLeft, strs);
        int pick = 0;
        if(zerosLeft >= zero && onesLeft >= one) 
            pick =  1 + solve(index + 1, zerosLeft- zero, onesLeft - one, strs);
        return dp[index][zerosLeft][onesLeft] = max(pick, skip);
        //return  max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size(),
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );
        return solve(0, m, n, strs);
    }
};