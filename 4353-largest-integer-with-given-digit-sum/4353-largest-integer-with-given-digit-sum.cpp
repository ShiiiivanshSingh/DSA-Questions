class Solution {
public:
    int largestInteger(int n, int s) {
        if (!s) return 0;
        if (s > 9 * n) return -1;

        string ans;
        while (n--) {
            int d = min(9, s);
            ans += '0' + d;
            s -= d;
        }
        return stoi(ans);
    }
};