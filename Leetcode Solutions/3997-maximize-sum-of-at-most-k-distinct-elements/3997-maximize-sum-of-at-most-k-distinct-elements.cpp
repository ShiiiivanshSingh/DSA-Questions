class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int ans=0;
        unordered_set<int> unique(nums.begin(), nums.end());
        vector<int> value(unique.begin(), unique.end());
        sort(value.begin(), value.end(), greater<int>());
        if(value.size()>k) value.resize(k);


        return value;
    }
};