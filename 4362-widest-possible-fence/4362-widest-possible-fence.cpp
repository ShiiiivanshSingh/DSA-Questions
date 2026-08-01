class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,long long> f, mp;
        for (int x : planks) f[x]++;
        vector<long long> v;
        for (auto &[x,c] : f) v.push_back(x);
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j)  mp[v[i] + v[j]] += f[v[i]] / 2;
                else  mp[v[i] + v[j]] += min(f[v[i]], f[v[j]]);
            }
        }
        long long ans = 0;
        for (auto &[x,c] : mp) ans = max(ans, c + f[x]);
        for (auto &[x,c] : f)   ans = max(ans, c);

        return ans;
    }
};