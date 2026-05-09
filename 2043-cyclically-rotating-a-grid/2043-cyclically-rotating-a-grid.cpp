class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();

        for (int l = 0; l < min(m, n) / 2; l++) {
            vector<int> x, y, a;

            for (int i = l; i < m - l - 1; i++) {
                x.push_back(i);
                y.push_back(l);
                a.push_back(g[i][l]);
            }

            for (int j = l; j < n - l - 1; j++) {
                x.push_back(m - l - 1);
                y.push_back(j);
                a.push_back(g[m - l - 1][j]);
            }

            for (int i = m - l - 1; i > l; i--) {
                x.push_back(i );
                y.push_back(n - l - 1);
                a.push_back(g[i][n - l - 1]);
            }

            for (int j = n - l - 1; j > l; j--) {
                x.push_back(l);
                y.push_back(j);
                a.push_back(g[l][j]);
            }

            int s = a.size();
            int r = k % s;

            for (int i = 0; i < s; i++) {
                g[x[i]][y[i]] = a[(i + s - r) % s];
            }
        }

        return g;
    }
};