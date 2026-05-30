class Solution {
public:
    vector<int> bit;

    void upd(int i, int v) {
        while (i < bit.size()) {
            bit[i] = max(bit[i], v);
            i += i & -i;
        }
    }

    int get(int i) {
        int res = 0;

        while (i) {
            res = max(res, bit[i]);
            i -= i & -i;
        }

        return res;
    }

    vector<bool> getResults(vector<vector<int>>& q) {

        int mx = 55554;

        set<int> st = {0, mx};

        for (auto &x : q) {
            if (x[0] == 1) {
                st.insert(x[1]);
            }
        }

        bit.resize(mx + 1);

        int pre = 0;

        for (int x : st) {
            if (x) {
                upd(x, x - pre);
                pre = x;
            }
        }

        reverse(q.begin(), q.end());

        vector<bool> ans;

        for (auto &x : q) {

            if (x[0] == 2) {

                int p = x[1];
                int sz = x[2];

                auto it = prev(st.upper_bound(p));

                int gap = max(get(*it), p - *it);

                ans.push_back(gap >= sz);
            }
            else {

                int p = x[1];

                auto it = st.find(p);

                int l = *prev(it);
                int r = *next(it);

                upd(r, r - l);

                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};