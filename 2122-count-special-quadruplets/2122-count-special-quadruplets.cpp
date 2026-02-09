class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

        int n = nums.size(), ans =0;
        // for(int i=0; i< n;i++) mp[nums[i]] = i;
        // ans hoga nums[a] + nums[b] = nums[d] − nums[c]
        for (int c = n - 2; c >= 2; c--) {
            unordered_map<int,int> mp;

            for (int d = c + 1; d < n; d++) {
                mp[nums[d] - nums[c]]++;
            }

            for (int a = 0; a < c; a++) {
                for (int b = a + 1; b < c; b++) {
                    int sum = nums[a] + nums[b];
                    if (mp.count(sum))  ans += mp[sum];
                }
            }
        }
        return ans;
    }
};