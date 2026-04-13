class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int MM = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                MM = min(MM, abs(i - start));
            }
        }
        return MM;
    }
};