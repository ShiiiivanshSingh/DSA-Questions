class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.size(); m++) {
            string ans;
            for (int i = m; i <= s.size(); i++) {
                string t = s.substr(i - m, m);
                if ((ans.empty() || t < ans) && count(t.begin(), t.end(), '1') == k)
                    ans = t;
            }
            if (!ans.empty()) return ans;
        }
        return "";
    }
};