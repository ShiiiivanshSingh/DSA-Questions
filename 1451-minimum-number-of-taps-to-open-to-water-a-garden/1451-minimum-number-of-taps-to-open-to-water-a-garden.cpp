class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      int first =0, last =0 , taps =0;
      while(n > last){
        for(int i=0;i< n+1 ; i++){
            int a = i - ranges[i]; // min dis
            int b = i + ranges[i]; // max dis
            if(a <= first && b >= last)   last = b;
        }
        if(last == first) return -1; //impos.
        taps++;
        first = last;
      }  
      return taps;
    }
};
// greedy ->
// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         int taps =0;
//         vector<int> dp(n+1 , -1);
//         for(int i=0;i<n + 1;i++){
//             // choosing the ennd point
//             if(ranges[i] == 0) continue;
//             int left = max( 0 , i - ranges[i]);
//             dp[left] = max(dp[left] , i+ ranges[i]); // changing to true val
//         }
         
//         int last =0;
//         int canReach =0;
//         for(int i=0;i<=n;i++){
//             if(i > last){
//                 if(canReach <=last) return -1; // impossible
//                 last = canReach;
//                 taps++;
//             }
//             canReach = max(canReach, dp[i]);
//         }
//         return taps+ (last<n);
//     }
// };