class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(), nums1.end());
        unordered_set<int> b(nums2.begin(), nums2.end());
        vector<int> v1, v2;
        for (int x : a) 
            if (!b.count(x)) 
                v1.push_back(x);
                
        for (int x : b) 
            if (!a.count(x)) 
                v2.push_back(x);
        

        return {v1, v2};
    }
};