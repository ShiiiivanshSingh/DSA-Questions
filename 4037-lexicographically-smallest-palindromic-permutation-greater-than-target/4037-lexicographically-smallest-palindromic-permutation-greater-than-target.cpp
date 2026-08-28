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

// //                 string p = x + mid + string(x.rbegin(), x.rend());

// //                 if (p > target) {
// //                     left += 'a' + j;
// //                     break;
// //                 }

// //                 cnt[j]++;
// //             }

// //             if (left.size() <= i) return "";
// //         }
// class Solution {
// public:
//     string lexPalindromicPermutation(string s, string target) {
//         int n = s.size();
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

//                 string p = x + (mid ? string(1, mid) : "") +
//                            string(x.rbegin(), x.rend());

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

// //         string r = left;
// //         reverse(r.begin(), r.end());
// //         return left + mid + r;
// //     }
// // };

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        if (n == 1) return s > target ? s : "";

        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                if (mid) return "";
                mid = 'a' + i;
            }
            cnt[i] /= 2;
        }

        string left;

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (!cnt[j]) continue;

                cnt[j]--;
                string x = left + char('a' + j);

                for (int c = 25; c >= 0; c--)
                    x += string(cnt[c], 'a' + c);

                string p = x + (mid ? string(1, mid) : "");
                p += string(x.rbegin(), x.rend());

                if (p > target) {
                    left += 'a' + j;
                    break;
                }

                cnt[j]++;
            }

            if (left.size() <= i) return "";
        }

        string r = left;
        reverse(r.begin(), r.end());

        return left + (mid ? string(1, mid) : "") + r;
    }
};