class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), s= 0, l= -1;
        int r = n, ans =n +1;

        while (l <n - 1 && s < x)   s += nums[++l];
        if (s ==x)  ans = l + 1;

        while (l >= 0) {
            s -= nums[l--];
            while (r > l + 1 && s < x)  s += nums[--r];
            if (s == x)  ans = min(ans,l + 1 + n - r);
        }

        return ans == n + 1 ?-1:ans;
    }
};