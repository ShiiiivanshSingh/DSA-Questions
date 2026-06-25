class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = 0;
            for (int j = i; j < nums.size(); j++) {
                x += nums[j] == target ? 1 : -1;
                ans += x > 0;
            }
        }

        return ans;
    }
};