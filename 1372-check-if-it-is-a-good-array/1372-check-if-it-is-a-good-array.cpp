class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int j = 0;
        for (int x : nums) j = __gcd(j, x);
        return j == 1;
    }
};