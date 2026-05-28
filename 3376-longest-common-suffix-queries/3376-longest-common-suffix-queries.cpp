class Trie {
public:
    int tr[500005][26]{}, len[500005], idx[500005];
    int tot = 0;

    Trie() {
        fill(len, len + 500005, 1e9);
        fill(idx, idx + 500005, 1e9);
    }

    void insert(string &s, int id) {

        int p = 0, n = s.size();

        if (n < len[0]) {
            len[0] = n;
            idx[0] = id;
        }

        for (int i = n - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (!tr[p][c]) {
                tr[p][c] = ++tot;
            }

            p = tr[p][c];

            if (n < len[p]) {
                len[p] = n;
                idx[p] = id;
            }
        }
    }

    int query(string &s) {

        int p = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (!tr[p][c]) break;

            p = tr[p][c];
        }

        return idx[p];
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& a,
                              vector<string>& q) {

        Trie t;

        for (int i = 0; i < a.size(); i++) {
            t.insert(a[i], i);
        }

        vector<int> ans;

        for (auto &s : q) {
            ans.push_back(t.query(s));
        }

        return ans;
    }
};