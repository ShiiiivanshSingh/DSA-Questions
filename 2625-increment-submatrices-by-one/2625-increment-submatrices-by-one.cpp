class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& qu) {
        int q=qu.size();
        vector<vector<int>> ans(n, vector<int> (n,0)), a(n+2, vector<int> (n+2, 0));
        for(int m=0;m<q;m++)
        {
            int r1=qu[m][0], c1=qu[m][1], r2=qu[m][2], c2=qu[m][3];
            a[r1+1][c1+1]++;
            a[r2+2][c2+2]++;
            a[r2+2][c1+1]--;
            a[r1+1][c2+2]--; 
        }

        for(int i=1;i<n+2;i++)
        {
            for(int j=1;j<n+2;j++)
            {
                a[i][j] += a[i][j-1];
            }
        }
        for(int j=1;j<n+2;j++)
        {
            for(int i=1;i<n+2;i++)
            {
                a[i][j] += a[i-1][j];
            }
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                ans[i-1][j-1] = a[i][j];
            }
        }
        return ans;
    }
};