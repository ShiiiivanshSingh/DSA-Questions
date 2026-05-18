class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(), k = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int y = i;
            int num = nums[n - 1 - i]; 
            if (num * y > sum) 
                k += 1;
            sum += num;
        }
        return k;
    }
};