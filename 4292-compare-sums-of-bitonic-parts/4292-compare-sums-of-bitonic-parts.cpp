using ll = long long;
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        ll a =0, b =0;
        for(int i=0;i<n;i++){
            if(nums[i] > nums[p]) p =i;
        }
        
        for(int i=0;i<=p;i++)    a += nums[i];
        for(int i=p;i<n;i++)    b += nums[i];
        if(a>b) return 0;
        if(b == a) return -1;
        if(b > a) return 1;
        return 1;
        
    }
};