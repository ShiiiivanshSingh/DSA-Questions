class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), sz = 1, last = 0;
        vector<map<int,int>> nxt(2*n+2);
        vector<int> link(2*n+2, -1), len(2*n+2, 0), cnt(2*n+2, 0);
        for (int x : nums) {
            int cur = sz++;
            len[cur] = len[last] + 1; cnt[cur] = 1;
            int p = last;
            while (p != -1 && !nxt[p].count(x)) { nxt[p][x] = cur; p = link[p]; }
            if (p == -1) link[cur] = 0;
            else {
                int q = nxt[p][x];
                if (len[p] + 1 == len[q]) link[cur] = q;
                else {
                    int c = sz++;
                    len[c] = len[p] + 1; nxt[c] = nxt[q]; link[c] = link[q];
                    while (p != -1 && nxt[p][x] == q) { nxt[p][x] = c; p = link[p]; }
                    link[q] = link[cur] = c;
                }
            }
            last = cur;
        }
        vector<int> bucket(n + 2, 0), ord(sz);
        for (int v = 0; v < sz; v++) bucket[len[v]]++;
        for (int i = 1; i <= n; i++) bucket[i] += bucket[i-1];
        for (int v = sz - 1; v >= 0; v--) ord[--bucket[len[v]]] = v;
        for (int i = sz - 1; i > 0; i--) {
            int v = ord[i];
            if (link[v] > 0) cnt[link[v]] += cnt[v];
        }
        int ans = n;
        for (int v = 1; v < sz; v++) if (cnt[v] == 1) ans = min(ans, len[link[v]] + 1);
        return ans;
    }
};