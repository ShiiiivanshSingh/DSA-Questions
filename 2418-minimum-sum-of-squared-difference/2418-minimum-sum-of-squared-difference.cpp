class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        


        vector<int> arr(100001);
        long long k = 1LL *k1 +k2, sum =0;
        int upper = 0;
        long long ans = 0;

        for(int i =0; i<nums1.size(); i++) {
            int curr =abs(nums1[i] -nums2[i]);
            arr[curr]++;
            sum +=curr;
            upper = max(upper,curr);
        }


        if(sum <= k) return 0;
        for(int i=upper; i >0&& k > 0; i--) {
            int move = min(k,(long long)arr[i]);
            arr[i]-=move;
            arr[i-1]+= move;
            k -= move;
        }
        for(int i = 1; i <= upper; i++)  ans += 1LL * i * i * arr[i];
        return ans;
    }
};