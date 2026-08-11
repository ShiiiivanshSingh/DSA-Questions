class Solution {
public:
    string longestPalindrome(string s) {

        string t = "^#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        t += '$';
        vector<int> p(t.size(), 0);
        int L = 0, R = 0,best = 0, center = 0;
        for (int i = 1; i < t.size() - 1; i++) {
            int mirror = L + R - i;
            if (i < R)   p[i] = min(R - i, p[mirror]);
            else p[i] = 0;
         //   p[i] = min(R - i, p[mirror]);
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > R) {
                L = i - p[i];
                R = i + p[i];
            }
            if (p[i] > best) {
                best = p[i];
                center = i;
            }
        }
        int start = (center - best) / 2;
        return s.substr(start, best);
    }
};