class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

          int x;
        if (k == 0) {
            x = INT_MAX;
        } else {
            x = nums[nums.size() - k];
        }

        int count = 0;
        for (int i : nums){ if
            (i < x ){ 
                count++;
            }
        }
        return count;
    }
};
