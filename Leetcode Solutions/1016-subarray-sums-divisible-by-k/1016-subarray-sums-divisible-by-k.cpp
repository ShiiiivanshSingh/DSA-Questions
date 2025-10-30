class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> count(k,0);
    count[0] = 1;
    int sum = 0, ans = 0;  
    
    for(int i:nums){
        sum =sum + i;
        int meowl = (sum%k +k ) % k;

        ans += count[meowl];
        count[meowl]++;
    } 
    return ans;
    }
};