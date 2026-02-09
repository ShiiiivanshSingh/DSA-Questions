class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size(), ans =0;
        unordered_map<int , int> mp;
        for(int i=0; i< n;i++) mp[nums[i]] = i;

        for(int i=0;i<n;i++){
            if(mp.count(nums[i] + diff) && mp.count(nums[i] + 2*diff)) ans++;
        }
        return ans;
    }

};