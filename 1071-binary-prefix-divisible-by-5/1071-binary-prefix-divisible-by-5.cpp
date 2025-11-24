class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        // vector<int> res;
        int i = 0;
        for (int bit : nums) {
            i = (i * 2 + bit) % 5;
            ans.push_back(i == 0);
        }   

        // for(int i = 0 ; i<n ; i++) {
        //     if(res[i] % 5 == 0) ans.push_back(1);
        //     else ans.push_back(0);
        // } 
    
    return ans;
    }
    
};