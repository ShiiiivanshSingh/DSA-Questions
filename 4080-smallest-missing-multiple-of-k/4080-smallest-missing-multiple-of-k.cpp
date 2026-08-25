class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int a = k ;    ; a += k) 
            if (!s.count(a)) 
                return a;
    }
};