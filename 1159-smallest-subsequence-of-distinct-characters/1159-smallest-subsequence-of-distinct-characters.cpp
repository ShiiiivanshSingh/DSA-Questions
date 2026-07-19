class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26), vis(26);
        for (char c : s) cnt[c - 'a']++;

        string ans;

        for (char c : s) {
            cnt[c - 'a']--;

            if (vis[c - 'a']) continue;

            while (!ans.empty() && ans.back() > c && cnt[ans.back() - 'a']) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans += c;
            vis[c - 'a'] = 1;
        }

        return ans;
    }
};