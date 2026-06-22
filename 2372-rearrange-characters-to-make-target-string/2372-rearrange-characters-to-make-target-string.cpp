class Solution {
public:
    int ans = 1e9;
    int rearrangeCharacters(string s, string t) {
        unordered_map<char,int> a, b;

        for (char c : s) a[c]++;
        for (char c : t) b[c]++;


        for (auto [c, x] : b) ans = min(ans, a[c] / x);

        return ans;
    }
};