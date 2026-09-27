class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>, int> mp;
        int cr = 0, mx = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])   cr++;
            else {
                auto p = minmax(nums[i], nums[i-1]);
                mx = max(mx, ++mp[p]);
            }
        }

        return cr + mx;
    }
};