class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        if(n == k) return 0;
        sort(nums.begin() , nums.end());
        int s1 =0, s2 = 0;
        
        for(int i=0;i<n;i++) cout << nums[i];
        cout << endl;
        for(int i =0  ; i< k;i++) s1 += nums[i];
        for (int i = n - 1; i >=  n-k; i--) {
            s2+= nums[i];
            cout << nums[i] << " ";
        }   cout << endl;
        
         cout << s1 <<" -> " << s2 << endl;
        ans = abs(s1-s2);
        return ans;
    }
};