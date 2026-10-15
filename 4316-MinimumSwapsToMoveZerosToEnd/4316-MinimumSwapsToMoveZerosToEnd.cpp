// Last updated: 10/15/2026, 12:41:18 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
       int l=0, r = nums.size() - 1 , ans =0;
        while(l<r){
            while(r>l && nums[l] !=0)l++;
            while(l<r && nums[r] == 0) r--;
            if(r>l) { ans++; 
                    r--;
                    l++;
                    }
        }
            return ans;
            
        }
    
};