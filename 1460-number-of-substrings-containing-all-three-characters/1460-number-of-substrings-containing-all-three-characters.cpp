class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> total(3);
        int ans = 0, left = 0;

        for (int r = 0; r < s.size(); r++) {
            total[s[r] - 'a']++;

            while (total[0] && total[1] && total[2]) {
                ans += s.size() - r;
                total[s[left++] - 'a']--;
            }
        }

        return ans;
    }
};