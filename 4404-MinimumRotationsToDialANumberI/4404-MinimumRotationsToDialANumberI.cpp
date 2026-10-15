// Last updated: 10/15/2026, 12:40:47 PM
class Solution {
public:
    int minRotations(string s) {
        int cur = 0, i = 0;
        for (char c : s) {
            int bee = abs(c-'0'-i);
            cur += min(bee, 10-bee);
            i = c - '0';
        }
        return cur;
    }
};