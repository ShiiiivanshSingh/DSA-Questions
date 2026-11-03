class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int c = n % 2 == 0 ? (nums[n/2 - 1] + nums[n/2]) / 2 : nums[n/2];
        for (int x : nums) ans += abs(x - c);
        return ans;
    }
};