class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> temp(nums.begin(), nums.end());

        for (int x : temp)
            if (!temp.count(x - 1)) {
                int y = x;
                while (temp.count(y + 1)) y++;
                ans = max(ans, y - x + 1);
            }

        return ans;
    }
};