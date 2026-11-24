class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            long long p = nums[i], g = nums[i], l = nums[i];
            for (int j = i + 1; j < n; j++) {
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (p > g * l) break;
                if (p == g * l) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};