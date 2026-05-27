class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0, n = word.size();
        vector<int> a(26, -1), b(26, -1);

        for (int i = 0; i < n; i++) {
            char x = word[i];
            if (islower(x)) a[x - 'a'] = i;
             else {
                
                if (b[x - 'A'] != -1) continue;
                else b[x - 'A'] = i;
                
            }

        }

        for (int i = 0; i < 26; i++) {

            if (b[i] != -1 && a[i] != -1) {
                if (a[i] < b[i]) ans++;
                else continue;
            }

        }
        return ans;
    }
};