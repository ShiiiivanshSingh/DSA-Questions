class Solution {
public:
    int minimumPushes(string w) {
        vector<int> f(26);
        for (char c : w) f[c - 'a']++;
        sort(f.rbegin(), f.rend());
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += (i / 8 + 1) * f[i];
        return ans;
    }
};