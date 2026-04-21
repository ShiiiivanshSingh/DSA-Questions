/**
 * // This is the Master's API interface.
 * // You should not implement i, or speculate about is implementation.
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

class Solution {
public:
    int matchCount(const string &a, const string &b) {
        int turns = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) turns++;
        }
        return turns;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> candidates(words.begin(), words.end());

        while (!candidates.empty()) {

            string  ans = *candidates.begin();

            int matched = master.guess(ans);

            for (auto i = candidates.begin(); i != candidates.end();) {
                if (matchCount(*i, ans) != matched)
                    i = candidates.erase(i);
                else
                    i++;
            }
            candidates.erase( ans );
        }
    }
};
