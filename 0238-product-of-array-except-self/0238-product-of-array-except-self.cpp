class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix =1;
        int suffix =1;
        vector<int> ans(n,0);
        vector<int> pref(n,1);
        vector<int> suff(n,1);
       
        
        for(int i=1;i<n;i++){
             pref[i] = pref[i-1]* nums[i-1];
             //cout << pref[i] << endl;
        }
        // cout << endl;
        for(int i=n-2;i>=0;i--){
             suff[i] = suff[i+1]* nums[i+1];
             //cout << suff[i] << endl;
        }
        for(int i=0;i<n;i++){
            //cout << suff[0] << " " << pref[0] << endl;
            ans[i] = suff[i] * pref[i];
        }
        return ans;
    }
};