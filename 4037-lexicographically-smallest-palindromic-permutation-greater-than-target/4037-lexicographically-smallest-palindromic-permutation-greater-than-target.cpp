// // // class Solution {
// // // public:
// // //     string lexPalindromicPermutation(string s, string target) {
// // //         int n = s.size();
// // //         vector<int> cnt(26);

// // //         for (char c : s) cnt[c - 'a']++;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), odd = 0, p = 0;
        vector<int> h(26);
        for (char c : s) h[c - 'a']++;
        string ans = s;
        for (int i = 0; i < 26; i++) {
            if (h[i] & 1) {
                odd++;
                ans[n / 2] = 'a' + i;
            }
            h[i] /= 2;
        }
        if (odd > 1) return "";
        while (p < n / 2 && h[target[p] - 'a']) {
            h[target[p] - 'a']--;
            p++;
        }
        for (int i = min(n - 1, p); i >= 0; i--) {
            if (i == n / 2) {
                for (int j = 0; j < n / 2; j++)
                    ans[j] = ans[n - 1 - j] = target[j];

                if (ans > target) return ans;
                continue;
            }
            int b = target[i] - 'a';
            if (i < p) h[b]++;
            int x = -1;
            for (int c = b + 1; c < 26; c++) {
                if (h[c]) {
                    h[c]--;
                    x = c;
                    break;
                }
            }
            if (x == -1) continue;
            for (int j = 0; j < i; j++) ans[j] = target[j];
            ans[i] = 'a' + x;
            int k = i + 1;
            for (int c = 0; c < 26; c++)
                while (h[c] && k < n / 2)
                    ans[k++] = 'a' + c, h[c]--;

            for (int j = 0; j < n / 2; j++)
                ans[n - 1 - j] = ans[j];

            return ans;
        }

        return "";
    }
};



// // //         char mid = 0;
// // //         for (int i = 0; i < 26; i++) {
// // //             if (cnt[i] & 1) {
// // //                 if (mid) return "";
// // //                 mid = 'a' + i;
// // //             }
// // //             cnt[i] /= 2;
// // //         }

// // //         string left;

// // //         for (int i = 0; i < n / 2; i++) {
// // //             for (int j = 0; j < 26; j++) {
// // //                 if (!cnt[j]) continue;

// // //                 cnt[j]--;
// // //                 string x = left + char('a' + j);

// // //                 for (int c = 25; c >= 0; c--)
// // //                     x += string(cnt[c], 'a' + c);

// // //                 string p = x + mid + string(x.rbegin(), x.rend());

// // //                 if (p > target) {
// // //                     left += 'a' + j;
// // //                     break;
// // //                 }

// // //                 cnt[j]++;
// // //             }

// // //             if (left.size() <= i) return "";
// // //         }
// // class Solution {
// // public:
// //     string lexPalindromicPermutation(string s, string target) {
// //         int n = s.size();
// //         vector<int> cnt(26);

// //         for (char c : s) cnt[c - 'a']++;

// //         char mid = 0;
// //         for (int i = 0; i < 26; i++) {
// //             if (cnt[i] & 1) {
// //                 if (mid) return "";
// //                 mid = 'a' + i;
// //             }
// //             cnt[i] /= 2;
// //         }

// //         string left;

// //         for (int i = 0; i < n / 2; i++) {
// //             for (int j = 0; j < 26; j++) {
// //                 if (!cnt[j]) continue;

// //                 cnt[j]--;
// //                 string x = left + char('a' + j);

// //                 for (int c = 25; c >= 0; c--)
// //                     x += string(cnt[c], 'a' + c);

// //                 string p = x + (mid ? string(1, mid) : "") +
// //                            string(x.rbegin(), x.rend());

// //                 if (p > target) {
// //                     left += 'a' + j;
// //                     break;
// //                 }

// //                 cnt[j]++;
// //             }

// //             if (left.size() <= i) return "";
// //         }

// //         string r = left;
// //         reverse(r.begin(), r.end());

// //         return left + (mid ? string(1, mid) : "") + r;
// //     }
// // };

// // //         string r = left;
// // //         reverse(r.begin(), r.end());
// // //         return left + mid + r;
// // //     }
// // // };

// class Solution {
// public:
//     string lexPalindromicPermutation(string s, string target) {
//         int n = s.size();
//         if (n == 1) return s > target ? s : "";

//         vector<int> cnt(26);
//         for (char c : s) cnt[c - 'a']++;

//         char mid = 0;
//         for (int i = 0; i < 26; i++) {
//             if (cnt[i] & 1) {
//                 if (mid) return "";
//                 mid = 'a' + i;
//             }
//             cnt[i] /= 2;
//         }

//         string left;

//         for (int i = 0; i < n / 2; i++) {
//             for (int j = 0; j < 26; j++) {
//                 if (!cnt[j]) continue;

//                 cnt[j]--;
//                 string x = left + char('a' + j);

//                 for (int c = 25; c >= 0; c--)
//                     x += string(cnt[c], 'a' + c);

//                 string p = x + (mid ? string(1, mid) : "");
//                 p += string(x.rbegin(), x.rend());

//                 if (p > target) {
//                     left += 'a' + j;
//                     break;
//                 }

//                 cnt[j]++;
//             }

//             if (left.size() <= i) return "";
//         }

//         string r = left;
//         reverse(r.begin(), r.end());

//         return left + (mid ? string(1, mid) : "") + r;
//     }
// };