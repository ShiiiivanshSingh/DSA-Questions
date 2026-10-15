// Last updated: 10/15/2026, 12:41:16 PM
using ll = long long;
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count =0;
        char req = x + '0';
        for(int i=0;i<nums.size();i++){
            ll sum =0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                ll val = abs(sum);
                
                if(val % 10 == x){
                    while(val >= 10)val = val /10;

                if(val ==x) count++;
                // string s = to_string(abs(sum += nums[j]));
                // if(s.front() == req && s.back() == req) count++;
                }
            }
        }
            return count;
    }
};