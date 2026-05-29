class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
         for(int i : nums){
            int curr =0 ; 
            while(i){
                curr = curr + i % 10;
                i = i /10;
            }
            ans = min(ans, curr);
         }
         return ans;
    }
};