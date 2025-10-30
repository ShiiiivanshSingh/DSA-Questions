class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
    for(int i:nums1) sum1+=i;
    for(int i:nums2) sum2+=i;
    if(sum1==sum2) return 0;


    if(sum1>sum2) return minOperations(nums2,nums1); 

        vector<int> arr;
        for(int i : nums1) arr.push_back(6 - i);
        for(int i : nums2) arr.push_back(i - 1);

        sort(arr.rbegin(), arr.rend());

        int diff = sum2 - sum1;
        int operation = 0;
        for(int i : arr){
            diff = diff - i;
            operation++;
            if(diff <= 0) return operation;
        }
    return -1;
    }
};