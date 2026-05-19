class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> K(nums1.begin(), nums1.end());
        for (int num : nums2) if (K.contains(num)) return num;
        return -1;
    }
};