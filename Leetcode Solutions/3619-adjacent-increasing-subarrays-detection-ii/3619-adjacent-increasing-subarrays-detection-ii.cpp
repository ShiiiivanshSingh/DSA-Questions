class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int a = 1;
        int b = 1;
        int j = 0;
        int last = 0;
        while(j<n-1){
            while(j<n-1 && nums[j]<nums[j+1]){
                a++;
                j++;
            }
            j++;
            ans=max(ans,a/2);
            ans=max(ans,min(last,a));
            while(j<n-1 && nums[j]<nums[j+1]){
                b++;
                j++;
            }
            j++;
            ans=max(ans,b/2);
            ans=max(ans,min(a,b));
            last = b;
            a=1;
            b=1;
        }
        return ans;
    }
};