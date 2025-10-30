class Solution {
public:
    int maxDistinctElements(vector<int>& nums,int k){

        sort(nums.begin(),nums.end());

        long long last = LLONG_MIN;
        int myau=0;

        for(auto x:nums){
            long long low = x - k;
            long long high = x + k;
            long long cand= max(last +1 ,low);
            if(cand<=high){
                myau++;
                last = cand;
            }
        }
        return myau;
    }
};
