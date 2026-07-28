class Solution {
public:
    string smallestPalindrome(string s) {
        int op = s.length();
        int x = op / 2;
        sort(s.begin(), s.begin() + x);
        for (int i = 0; i < x; ++i)   s[op - 1 - i] = s[i];
        
  return s;
    }
};