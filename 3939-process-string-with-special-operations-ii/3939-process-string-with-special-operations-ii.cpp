// using ll = long long;
// class Solution {
// public:
//     char processStr(string s, long long k) {
//         string res, temp = s;
//         ll w = s.size();
//         for (int i = 0; i < w; i++) {
//             if (s[i] == '*') {
//                 if (!res.empty())
//                     res.pop_back();
//             } else if (s[i] == '#')
//                 res.append(res);

//             else if (s[i] == '%')
//                 reverse(res.begin(), res.end());

//             else
//                 res.push_back(s[i]);
//         }

//         if (k < res.size())
//             return res[k];
//         else
//             return '.';
//     }
// };
using ll = long long;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<ll> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            len[i + 1] = len[i];

            if ('a' <= s[i] && s[i] <= 'z')
                len[i + 1]++;
            else if (s[i] == '*') {
                if (len[i + 1] > 0)
                    len[i + 1]--;
            }
            else if (s[i] == '#')
                len[i + 1] = min((ll)1e15, len[i] * 2);
            else if (s[i] == '%');
        }

        if (k >= len[n])
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i])
                    return c;
            }
            else if (c == '#') {
                k %= len[i];
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
            else if (c == '*') {
                if (len[i] > len[i + 1]) {
                    if (k == len[i])
                        return '.';
                }
            }
        }

        return '.';
    }
};