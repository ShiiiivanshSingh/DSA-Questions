class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        duhh(nums, 0, temp);
        return result;
    }

    void duhh(vector<int>& nums, int start, vector<int>& temp) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            duhh(nums, i + 1, temp);
            temp.pop_back();
        }
    }
};
