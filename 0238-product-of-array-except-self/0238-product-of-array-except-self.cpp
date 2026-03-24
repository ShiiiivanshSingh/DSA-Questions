class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix =1, suffix =1;
        vector<int> ans(n,0), pref(n,1), suff(n,1);
 
        for(int i=1;i<n;i++)
            pref[i] = pref[i-1]* nums[i-1];
   
        for(int i=n-2;i>=0;i--)
            suff[i] = suff[i+1]* nums[i+1];
     
        for(int i=0;i<n;i++)
            ans[i] = suff[i] * pref[i];
        
        return ans;
    }
};