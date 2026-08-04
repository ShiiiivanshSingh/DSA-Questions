class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for(int j =0;j<n;j++){
                if(nums[i] > nums[j]) curr++;
            }

            ans.push_back(curr);
        }
        return ans;
    }
};