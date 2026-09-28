class Solution {
    int n, m;
    int dp[200][200]{};

    int dfs(vector<vector<int>>& a, int i, int j) {
        int ans = 1;
        if(i < 0 || j < 0 || i >= n || j >= m)  return 0;
        if(dp[i][j])  return dp[i][j];

        if(i >0 && a[i-1][j] > a[i][j])  ans = max(ans, 1+ dfs(a, i-1, j));
        if(i+1< n && a[i+1][j]> a[i][j])  ans = max(ans, 1+ dfs(a, i+1,j));
        if(j > 0 && a[i][j-1] >a[i][j])  ans = max(ans,1 + dfs(a, i, j-1));
        if(j+1 < m && a[i][j+1] > a[i][j])  ans = max(ans, 1 + dfs(a, i, j+1));

        return dp[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();  m = matrix[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)   ans = max(ans, dfs(matrix, i, j));

        return ans;
    }
};