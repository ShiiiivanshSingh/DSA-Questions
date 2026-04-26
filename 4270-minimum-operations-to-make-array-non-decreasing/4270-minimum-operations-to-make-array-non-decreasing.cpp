class Solution {
public:
    long long minOperations(vector<int>& nums) {
     //   ll a =0;
        long long ans =0;
        int prev = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] < prev){
                ans =  ans + (prev - nums[i]);

            prev= nums[i];    
            }
            else 
                prev = nums[i];
            
        }
        return ans;
    }
};