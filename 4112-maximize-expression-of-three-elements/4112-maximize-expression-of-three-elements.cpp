class Solution {
public:
  int maximizeExpressionOfThree(vector<int>& nums)
    
    
     {
        sort(nums.begin()  ,nums.end());
        int n= nums.size();
        return nums[n-1] + nums[n-2] - nums[0];
     }
    //     int n = nums.size();
    //     int myau = INT_MIN;
    //     if(n<3) return 0;
    //     // vector<int> A(n);
    //     // vector<int> AB(n , INT_MIN);
    //     int max1 = INT_MIN, max2 = INT_MIN ,max3 =INT_MIN;
    //     int min1 = 10e7;

    //     for(int i: nums){
    //         if(i>max1){
    //             max2 = max1;
    //             max1=i;
    //         }
    //             else if (i > max2) {
    //                 max2 = i;
    //             }




    //         if(i < min1) min1 = i;
    //     }

    //     return max1 + max2 - min1;

    //     // A[0] = nums[0];
    //     // for(int i =1 ; i< n;i++){
    //     //     A[i] = max(A[i-1] , nums[i]);
    //     // }
    //     // for(int i =1; i<n;i++){
    //     //     AB[i] = max(AB[i-1] , A[i-1] + nums[i] );
    //     // }
        
    //     //  for(int i =2; i<n;i++){
    //     //      myau= max(myau , AB[i-1] - nums[i]);
    //     //  }
    //     // return myau;
    // }
};