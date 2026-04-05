
// using ll = long long;
// class Solution {
// public:
//     long long minIncrease(vector<int>& nums) {
//         int n= nums.size();
//         if(n <3) return 0;
//      //   vector<int> odd = nums;
//        // vector<int> even = nums;
//         bool flag =0;
//         int a =0, b =0;
//         ll x = 0;
//         for(int i=1;i<n-1;i+=2){
//             a++;
//             int k = max(nums[i-1] , nums[i+1]);
//             k++;
            
//             if(k >nums[i]){
//                 x = x + (k - nums[i]);
//                // nums[i] = k;
//             }
//         }

//         ll y =0;
//         for(int i=2;i<n-1;i+=2){
//             b++;
//            flag =1;
//             int k = max(nums[i-1], nums[i+1]);
//             k++;
//             if(k > nums[i]){
//                 y = y + (k - nums[i]);
//                // nums[i] = k;
//             }
//         }
//         if(a>b) return x;
//         if(b>a) return y;
//          return min(x,y);
//     }
// };
using ll = long long;
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<ll> cost(n, 0);
        vector<pair<int, ll>> dp(n, {0, 0});

        
            
        for (int i = 1; i < n - 1; i++) {
            ll k = max(nums[i - 1], nums[i + 1]);
            k++;
            
            if (k > nums[i])
                cost[i] = k - nums[i];
        }
        for (int i = 1; i < n - 1; i++) {
            

           // for (int i = 1; i < n - 1; i++) {
                dp[i] = dp[i - 1];
                int a = 1;
                ll b = cost[i];
                if (i > 1) {
                    a += dp[i - 2].first;
                    b += dp[i - 2].second;
                }

            
                if (a > dp[i].first || (a == dp[i].first && b < dp[i].second))
                    dp[i] = {a, b};
            }
       // }
        return dp[n - 2].second;
    }
};