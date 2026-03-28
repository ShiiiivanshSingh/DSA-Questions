class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int a = -1, b = -1, ans =INT_MAX;
        int n  = nums.size();
        for(int i=0;i<n;i++){
                if(nums[i] == 1) a =i;
                if(nums[i] == 2) b =i;
                if(a != -1 && b != -1){
                    int x = abs(a -b);    
                    ans = min(ans, x);
                } 
        }
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};