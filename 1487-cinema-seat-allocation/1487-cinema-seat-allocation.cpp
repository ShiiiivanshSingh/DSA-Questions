class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int, vector<int>> mp;

        for (auto &x : a) mp[x[0]].push_back(x[1]);
        int ans = (n - mp.size()) * 2;


        for (auto &[r, v] : mp) {
            bool l = 1, m = 1, rr = 1;

            for (int x : v) {
                if (x >= 2 && x <= 5) l = 0;
                if (x >= 4 && x <= 7) m = 0;
                if (x >= 6 && x <= 9) rr = 0;
            }

            if (l && rr)   ans += 2;
            else if (l || m || rr)  ans++;
        }

        return ans;
    }
};