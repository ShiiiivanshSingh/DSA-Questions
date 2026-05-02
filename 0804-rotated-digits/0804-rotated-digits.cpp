class Solution {
public:
using ll = long long;

    bool ok(int n) {
        bool bad = 0, diff = 0;
        while (n > 0) {
            int d = n % 10;

            if (d == 3 || d == 4 || d == 7) bad = 1;
            if (d == 2 || d == 5 || d == 6 || d == 9) diff = 1;

            n /= 10;
        }

        if (bad) return 0;
        if (diff) return 1;
        return 0;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (ok(i)) ans++;
        }

        return ans;
    }
};