using ll = long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        ll prefix =0;
        ll temp =LLONG_MIN;
        vector<ll> sum(k, LLONG_MAX);

        for(int i =0 ;i<nums.size(); i++){
            prefix += nums[i];
            int len = (i+1) % k;

            if ((i + 1) % k == 0) temp = max(temp, prefix);

            if(sum[len] != LLONG_MAX) temp = max(temp , prefix - sum[len]);
            
            sum[len] = min(sum[len], prefix);
        }
        return temp;
    }
};