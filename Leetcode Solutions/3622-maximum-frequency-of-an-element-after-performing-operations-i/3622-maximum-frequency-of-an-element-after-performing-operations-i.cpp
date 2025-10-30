class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto n : nums)
        {
            maxi = max(maxi,n);
            mini = min(mini,n);
        }
        int ans=0;
        int n = nums.size();


        vector<int>freq(maxi+1,0);
        for(auto n:nums)
        {
            freq[n]++;
        }


        for(int i=1;i<=maxi;i++)
        {
            freq[i]+=freq[i-1];
        }

        for(int curr=mini;curr<=maxi;curr++)
        {

            int l=max(mini,curr-k);
            int r = min(maxi,curr+k);

            int f = freq[curr]-freq[curr-1];

   
            int availableDonors = (freq[r]-freq[l-1]) - f;

            int extra = min(numOperations, availableDonors);


            ans = max(ans,f+extra);
        }

        return ans;
    }
};