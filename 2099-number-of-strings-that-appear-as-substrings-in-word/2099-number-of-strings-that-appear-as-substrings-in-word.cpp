class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (auto &s : patterns) {
            bool ok = 0;
            for (int i = 0; i + s.size() <= word.size(); i++)
                if (word.substr(i, s.size()) == s)
                    ok = 1;
            ans += ok;
        }

        return ans;
    }
};