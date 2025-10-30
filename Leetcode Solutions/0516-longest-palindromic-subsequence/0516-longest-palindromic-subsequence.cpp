class Solution {
public:

int longestPalindromeSubseq(string s) {
    int n = s.size();

    vector<vector<int>> myau( n , vector<int>(n,0));

    for(int i =0 ;i<n;i++) myau[i][i] = 1;
    for(int i = 2;i<=n;i++){
        for(int j =0; j+i-1<n;j++){

            int k = i+j-1;

            if(s[j] == s[k]) myau[j][k] = myau[j+1][k-1] +2;
            else myau[j][k] = max(myau[j+1][k] , myau[j][k-1]);
        }
    }
    return myau[0][n-1];
}

};