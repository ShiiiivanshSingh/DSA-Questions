class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<bool> dp(k+1, false);
        vector<bool> answer(n, false);
        dp[0] = true;

        for(int i = 0, x=1; x<=n;x++){
            while(i<n && nums[i] <x){
                for(int j = k;j>=nums[i]; j--){
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                i++;
            }
            int myau=n-i;
            for(int a=0;a<=myau && k>= a*x; a++){
                if(dp[k-a*x] == 1){
                    answer[x-1] =1;
                    break;
                }
            }
        }
        return answer;
    }
};