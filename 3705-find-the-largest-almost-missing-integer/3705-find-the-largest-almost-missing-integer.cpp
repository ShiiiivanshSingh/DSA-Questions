class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size(), c[51] = {}, ans = -1;
        if (n == k) 
            return *max_element(nums.begin(), nums.end());

        for (int x : nums) c[x]++;
        if (k == 1) {
            for (int i = 50; i >= 0; i--)
                if (c[i] == 1) 
                    return i;
            return -1;
        }

        if (c[nums[0]] == 1) 
            ans = nums[0];
        if (c[nums[n - 1]] == 1) 
            ans = max(ans, nums[n - 1]);
        return ans;
    }
};