// Last updated: 10/15/2026, 12:40:54 PM
class Solution {
    void helper(vector<int>& nums, vector<int>& ans, int k) {
        if (k == nums.size()) return;

        int pre = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != pre && nums[i] != -1) {
                ans[k++] = pre = nums[i];
                nums[i] = -1;
            }
        }
        helper(nums, ans, k);
    }

public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        helper(nums, ans, 0);
        return ans;
    }
};