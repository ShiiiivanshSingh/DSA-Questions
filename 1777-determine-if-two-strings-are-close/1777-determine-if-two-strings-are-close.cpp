class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        if (m != n) return 0;
        set<char> a(word1.begin(), word1.end());
        set<char> b(word2.begin(), word2.end());
        if (a != b) return 0;


        vector<int> f1(26, 0), f2(26, 0);
        for (char c : word1) f1[c - 'a']++;
        for (char c : word2) f2[c - 'a']++;

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;
    }
};