class Solution {
public:
    int isValid(vector<int> nums, int i, int dir) {
        while (0 <= i && i < nums.size()) {
            if (nums[i] > 0) {
                nums[i]--;
                dir = 0 - dir;
            }
            i += dir;
        }
        for (auto& num : nums) {
            if (num)
                return 0;
        }
        return 1;
    }

    int countValidSelections(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count += isValid(nums, i, -1);
                count += isValid(nums, i, 1);
            }
        }
        return count;
    }
};