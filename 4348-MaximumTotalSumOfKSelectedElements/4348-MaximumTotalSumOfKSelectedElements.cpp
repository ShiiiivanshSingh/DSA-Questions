// Last updated: 10/15/2026, 12:41:04 PM
using ll = long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        ll ans =0;
        sort(nums.rbegin(), nums.rend());
        
        for(int i=0;i<k;i++){
            ll op = max(1 , mul -i);
            ll op2 =  1LL*nums[i]* op;
            ans = ans + op2;
        }
        return ans;
    }
};