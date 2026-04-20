class Solution {
public:
int twoEggDrop(int n) {
    int ans[n+1];
    
    memset(ans, 0x3f, sizeof(ans));   //??
    ans[0]  = 0; //0 floor
    for(int i = 1 ; i<= n;i++){
        for(int drop_floor = 1;drop_floor <= i ;drop_floor++  ){
            int if_break = drop_floor -1;
            int if_survive = ans[ i - drop_floor];

            ans[ i] = min(ans[i] , 1 + max(if_break, if_survive));

            // cout << if_break << " n " << if_survive << " on floor -> " << drop_floor <<"\n" ;
        }
        // cout << ans[i] << " is given " << "\n";
    }
    return ans[n];
}
};

// {  
//     int dp[n + 1];    
//     memset(dp, 0x3f, sizeof(dp));   
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int drop = 1; drop <= i; drop++) {
//             int breaks = drop - 1;
//             int survive = dp[i - drop];
//             dp[i] = min(dp[i], 1 + max(breaks, survive));
//             cout << drop << " " <<breaks << " " << survive << "\n";
//         }
        
//     }
//     return dp[n];
// }





// class Solution {
// public:
// int twoEggDrop(int n) {
//     int ans[n+1];
    
//     memset(ans, 0x3f, sizeof(ans));   //??
//     ans[0]  = 0; //0 floor
//     for(int i = 1 ; i<= n;i++){
//         for(int drop_floor = 1;drop_floor <= i ;drop_floor++  ){
//             int if_break = drop_floor -1;
//             int if_survive = ans[ i - drop_floor];

//             ans[ i] = min(ans[i] , 1 + max(if_break, if_survive));
//         }
//     }
//     return ans[n];
// }
// };

// // {  
// //     int dp[n + 1];    
// //     memset(dp, 0x3f, sizeof(dp));   
// //     dp[0] = 0;
// //     for (int i = 1; i <= n; i++) {
// //         for (int drop = 1; drop <= i; drop++) {
// //             int breaks = drop - 1;
// //             int survive = dp[i - drop];
// //             dp[i] = min(dp[i], 1 + max(breaks, survive));
// //             cout << drop << " " <<breaks << " " << survive << "\n";
// //         }
        
// //     }
// //     return dp[n];
// // }