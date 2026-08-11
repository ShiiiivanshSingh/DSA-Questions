class Solution {
public:
using ll = long long;
ll base = 31;
ll mod = 1e9 + 7;
//vector<int> dp;
    // bool isPalindrome(string& s, int end) {
    //     int l = 0;
    //     int r = end;
    //     while (l < r) {
    //         if (s[l] != s[r]) return 0;
    //         l++;  r--;
    //     }
    //     return 1;
    // }
    ll value(char k){
        return k - 'a' + 1;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
     //   dp.assign(n, -1);
    // int longest = 0;
    ll forward = 0, rev = 0, power = 1;
    int longest = 0;
        for (int i = 0; i < n; i++) {
            forward = forward * base + value(s[i]);
            forward  %= mod;
            rev = rev + value(s[i]) * power;
            rev  %= mod;
            power *= base;
            power  %= mod;
             if(forward == rev) longest = i + 1;
        }
        
        string suffix = s.substr(longest);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};