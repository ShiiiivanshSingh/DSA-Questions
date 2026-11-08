class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), ans = 0;
        vector<int> r(m),c(n);

        for (int i = 0; i<m; i++)
            for (int j = 0; j<n; j++)
                r[i]+=g[i][j],c[j]+= g[i][j];


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += g[i][j] &&(r[i]>1 ||c[j]> 1);

        return ans;
    }
};