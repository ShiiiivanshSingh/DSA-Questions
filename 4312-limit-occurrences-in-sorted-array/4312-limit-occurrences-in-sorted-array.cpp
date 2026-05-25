class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> arr;
        unordered_map<int, int> time;
        for(int i=0;i<nums.size();i++){
            if(time[nums[i]] < k) {
                arr.push_back(nums[i]);
                time[nums[i]]++;
            }
        }
        return arr;
    }
};