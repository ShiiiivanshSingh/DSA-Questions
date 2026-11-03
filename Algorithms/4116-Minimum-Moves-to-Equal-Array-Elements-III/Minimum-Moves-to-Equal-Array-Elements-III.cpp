class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0, op=*max_element(nums.begin(), nums.end());
        for (int i :nums) ans +=op-i;
        return ans;
    }
};