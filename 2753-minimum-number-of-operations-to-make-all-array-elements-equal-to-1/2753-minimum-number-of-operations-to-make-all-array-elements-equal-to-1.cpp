class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int len  = INT_MAX;


    int ohne = count(nums.begin() , nums.end() ,  1);
    if(ohne > 1){
        return n-ohne;
    }
     for(int  i = 0 ; i<n;i++){
        int g = nums[i];
        for(int j = i ; j<n ; j++){
            g = gcd(g , nums[j]);


            if(g == 1){
                len = min(len , j+1 - i);
                break;
            }
        }
     }
    //  } if(len = 10e7) return -1; 
cout << len;
    if(len == INT_MAX){ 
        
        return -1; 
    }
      return (len - 1) + ( n -1);
    }
};