class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i], s = 0;
            while (n) {
                s = s +  n % 10;
                n /= 10;
            }
            if (s == i)  return i;
        }
        return -1;
    }
};