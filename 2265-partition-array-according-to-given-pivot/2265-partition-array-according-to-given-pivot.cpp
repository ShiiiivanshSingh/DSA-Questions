class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {

        vector<int> a;
        for (int x : nums) if (x < p) a.push_back(x);
        for (int x : nums) if (x == p) a.push_back(x);
        for (int x : nums) if (x > p) a.push_back(x);

        return a;
    }
};