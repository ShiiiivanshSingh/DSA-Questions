class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int k = *max_element(nums.begin(),nums.end());
        int time =0;
        for (int x : nums) {
            if (x == nums.size() - 1) time++;
        }
        
        return (s.size() == k) && (time == 2);
    }
};