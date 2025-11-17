class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
  
        int  prev = -(k + 1);
           for(int i = 0 ; i< nums.size() ;++i){
             if(nums[i] == 1){
                if( i-  1 - prev < k) return 0;
          
            prev= i;
              } 
        }
        return 1;
    }
};