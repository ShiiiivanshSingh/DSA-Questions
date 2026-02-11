class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i : nums)
            total += i;


        return (n*(n+1))/2 - total;
    }
};