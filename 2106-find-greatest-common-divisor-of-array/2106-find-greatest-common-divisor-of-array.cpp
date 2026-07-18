class Solution {
public:
    int findGCD(vector<int>& nums) {
        int myau = *max_element(nums.begin(), nums.end()), bhau = *min_element(nums.begin(), nums.end());
        return gcd(myau, bhau);
    }
};