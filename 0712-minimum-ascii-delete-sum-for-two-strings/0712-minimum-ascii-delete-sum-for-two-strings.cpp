class Solution {
public:
    int solve(int i,string &s1,int j,string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=(int)s1[i] + solve(i-1,s1,j-1,s2,dp);
        }else{
            return dp[i][j]=max(solve(i,s1,j-1,s2,dp),solve(i-1,s1,j,s2,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int a=0;
        for(int i=0;i<n;i++){
            a+=(int)s1[i];
        }
        int b=0;
        for(int i=0;i<m;i++){
            b+=(int)s2[i];
        }
        vector<vector<int>>dp(n,(vector<int>(m,-1)));
        int maxiKeep= solve(n-1,s1,m-1,s2,dp);

        return a+b-2*maxiKeep;
    }
};