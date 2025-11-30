class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long T = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = T % p;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = n;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            mp[sum % p] = i;
            int r = sum % p;
            if(mp.count((r - rem + p) % p)){
                ans = min(ans, i - mp[(r - rem + p) % p]);
            }
        }
        return ans == n ? -1 : ans;
    }
};