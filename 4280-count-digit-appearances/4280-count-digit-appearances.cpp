class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
       map<int, int> mp;
       int ans =0;
       for(auto i : nums){
        if(i==0) mp[0]++;
        while(i >0){
            mp[i % 10]++;
            i /=10;
        }
       }
       return mp[digit]; 
    }
};