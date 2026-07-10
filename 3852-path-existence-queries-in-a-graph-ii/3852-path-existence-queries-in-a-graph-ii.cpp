class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {nums[i], i};
        sort(a.begin(), a.end());

        vector<int> pos(n), L(n), R(n);
        for (int i = 0; i < n; i++) pos[a[i].second] = i;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && a[j + 1].first - a[i].first <= maxDiff) j++;
            R[i] = j;
            if (j < i) j = i;
        }

        j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j && a[i].first - a[j - 1].first <= maxDiff) j--;
            L[i] = j;
            if (j > i) j = i;
        }

        int LOG = __lg(n) + 1;
        vector<vector<int>> upR(LOG, R), upL(LOG, L);

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++) {
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
            }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]], v = pos[q[1]], cur, step = 0;

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u < v) {
                if (R[u] == u) {
                    ans.push_back(-1);
                    continue;
                }
                cur = u;
                for (int k = LOG - 1; k >= 0; k--)
                    if (upR[k][cur] < v)
                        cur = upR[k][cur], step += 1 << k;

                ans.push_back(R[cur] < v ? -1 : step + 1);
            } else {
                if (L[u] == u) {
                    ans.push_back(-1);
                    continue;
                }
                cur = u;
                for (int k = LOG - 1; k >= 0; k--)
                    if (upL[k][cur] > v)
                        cur = upL[k][cur], step += 1 << k;

                ans.push_back(L[cur] > v ? -1 : step + 1);
            }
        }

        return ans;
    }
};