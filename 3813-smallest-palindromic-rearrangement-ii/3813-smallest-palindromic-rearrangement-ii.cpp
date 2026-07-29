class Solution {
public:
    long long C(long long n, long long r, long long k) {
        long long ans = 1;
        r = min(r, n - r);
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans > k) return k + 1;
        }
        return ans;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.size(), m = n / 2;
        vector<int> cnt(26);

        for (int i = 0; i < m; i++) cnt[s[i] - 'a']++;

        auto calc = [&](int rem) {
            long long ans = 1;
            for (int i = 0; i < 26; i++) {
                if (!cnt[i]) continue;
                ans *= C(rem, cnt[i], k);
                if (ans > k) return ans;
                rem -= cnt[i];
            }
            return ans;
        };

        string l;
        long long cur = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                if (!cnt[j]) continue;
                cnt[j]--;

                long long ways = calc(m - i - 1);
                if (cur + ways > k) {
                    l += char('a' + j);
                    break;
                }

                cnt[j]++;
                cur += ways;
            }
        }

        if (l.size() < m) return "";

        string r = l;
        reverse(r.begin(), r.end());

        return l + (n & 1 ? string(1, s[m]) : "") + r;
    }
};