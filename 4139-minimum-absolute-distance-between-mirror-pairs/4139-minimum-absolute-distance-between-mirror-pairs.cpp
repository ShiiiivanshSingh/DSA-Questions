class Solution {
public:
    int rev(int n){
        int r=0;
        while(n){
            r = r*10 + n % 10;
            n = n/10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n +1;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(prev.count(curr)) ans = min(ans , i - prev[curr]);
            prev[rev(curr)] = i;
        }
        if(ans == n+1) return -1;
        return ans;
    }
};