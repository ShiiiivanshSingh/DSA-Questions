class Solution {
public:
int j;
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return 0;

        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) freq[s[i] - 'a']++;
        for (j = 0; j < t.length(); j++) {
            freq[t[j] - 'a']--;
            if (freq[t[j] - 'a'] < 0) return 0;
        }
        
        if(j == t.length()) return 1;
        return  0;
    }
};