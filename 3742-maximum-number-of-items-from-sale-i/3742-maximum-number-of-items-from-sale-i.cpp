// class Solution {
// public:
//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         int n = items.size();
//         vector<int> dp(budget + 1,0);

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i == j) continue;

//                 if(items[j][0] % items[i][0] == 0){
//                     int cost = items[i][1];
//                     for(int k = cost; k<= budget; k++){
//                         dp[k] = max(dp[k], dp[k - cost] + 2);
//                     }
//                 }
//             }
//         }

//         for(int i=0;i<n;i++){
//         int cost = items[i][1];
//             for(int j = cost; j<= budget;j++){
//                 dp[j] = max(dp[j] , 1+dp[j-cost]);
//             }
//         }
//         return dp[budget];
//     }
// };

// // // class Solution {
// // // public:
// // //     int maximumSaleItems(vector<vector<int>>& items, int budget) {
// // //         int ans =0, n = items.size();
// // //         vector<int> 
// // //         for(int i=0;i <n;i++){
// // //             int k = items[i][0];
// // //             int k2 = items[i][1];
// // //             int x =0;


// // //             int b = budget / k2;
// // //             if(!b) continue;
// // //             for(int j =0;j<n;j++){
// // //                 if(j != i && items[j][0] % k == 0) x++;
// // //             }
// // //             ans = max(ans , b + x);
// // //         }
// // //         return ans;
// // //     }
// // // }; //

// // // this is exact same solution of C
// // // i did C first hopefully this will do as well
// // using ll = long long;
// // class Solution {
// // public:
// //     int maximumSaleItems(vector<vector<int>>& items, int budget) {
// //         ll n = items.size(), small = LLONG_MAX;
// //         for(auto & i : items) small = min(small , (ll)i[1]);
// //         vector<ll> total(1501, 0) , x(1501 ,0); // 1 <= budget <= 1500
// //         for(auto &i:items) total[i[0]]++;
// //         for(int i=1;i<=n;i++) for(int j = i; j<=n;j+=i) x[i]+= total[j];


// //         vector<int> dp(budget + 1, 0);
// //         for(auto &i: items) {
// //             int price = i[1];
// //             int factor = i[0];
// //             if (price <= budget) {
// //                 int total_gain = x[factor]; 
// //                 for (int w = budget; w >= price; w--) {
// //                     dp[w] = max(dp[w], dp[w - price] + total_gain);
// //                 }
// //             }
// //         }
// //         int ans = 0;
// //         for (int w = 0; w <= budget; w++) {
// //             int leftover = budget - w;
// //             int extra = leftover / small;
// //             ans = max(ans, dp[w] + extra);
// //         }
// //         return ans;
        
// //     }
// // };
// class Solution {
// public:
//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         int n = items.size();
//         vector<int> dp(budget + 1,0);

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i == j) continue;

//                 if(items[j][0] % items[i][0] == 0){
//                     int cost = items[i][1];
//                     for(int k = cost; k<= budget; k++){
//                         dp[k] = max(dp[k], dp[k - cost] + 2);
//                     }
//                 }
//             }
//         }

//         for(int i=0;i<n;i++){
//         int cost = items[i][1];
//             for(int j = cost; j<= budget;j++){
//                 dp[j] = max(dp[j] , 1+dp[j-cost]);
//             }
//         }
//         return dp[budget];
//     }
// };

// // // class Solution {
// // // public:
// // //     int maximumSaleItems(vector<vector<int>>& items, int budget) {
// // //         int ans =0, n = items.size();
// // //         vector<int> 
// // //         for(int i=0;i <n;i++){
// // //             int k = items[i][0];
// // //             int k2 = items[i][1];
// // //             int x =0;


// // //             int b = budget / k2;
// // //             if(!b) continue;
// // //             for(int j =0;j<n;j++){
// // //                 if(j != i && items[j][0] % k == 0) x++;
// // //             }
// // //             ans = max(ans , b + x);
// // //         }
// // //         return ans;
// // //     }
// // // }; //

// // // this is exact same solution of C
// // // i did C first hopefully this will do as well
// // using ll = long long;
// // class Solution {
// // public:
// //     int maximumSaleItems(vector<vector<int>>& items, int budget) {
// //         ll n = items.size(), small = LLONG_MAX;
// //         for(auto & i : items) small = min(small , (ll)i[1]);
// //         vector<ll> total(1501, 0) , x(1501 ,0); // 1 <= budget <= 1500
// //         for(auto &i:items) total[i[0]]++;
// //         for(int i=1;i<=n;i++) for(int j = i; j<=n;j+=i) x[i]+= total[j];


// //         vector<int> dp(budget + 1, 0);
// //         for(auto &i: items) {
// //             int price = i[1];
// //             int factor = i[0];
// //             if (price <= budget) {
// //                 int total_gain = x[factor]; 
// //                 for (int w = budget; w >= price; w--) {
// //                     dp[w] = max(dp[w], dp[w - price] + total_gain);
// //                 }
// //             }
// //         }
// //         int ans = 0;
// //         for (int w = 0; w <= budget; w++) {
// //             int leftover = budget - w;
// //             int extra = leftover / small;
// //             ans = max(ans, dp[w] + extra);
// //         }
// //         return ans;
        
// //     }
// // };
using ll = long long;
class Solution {
public:
    unordered_map<ll,ll> mp;
    vector<vector<ll>> dp, a;
    ll small = LLONG_MAX;

    ll dfs(ll i, ll b) {

        if (i == a.size())  return b / small;
        if (dp[i][b] != -1) return dp[i][b];

        ll ans = dfs(i + 1, b);

        ll f = a[i][0], c = a[i][1];
        if (c <= b) ans = max(ans, mp[f] + dfs(i + 1, b - c));
        return dp[i][b] = ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        for (auto &v : items) {

            ll f = v[0], c = v[1];

            a.push_back({f, c});

            small = min(small, c);

            for (ll i = 1; i * i <= f; i++) {

                if (f % i) continue;
                mp[i]++;
                if (i * i != f)  mp[f / i]++;
                
            }
        }

        dp.assign(a.size(), vector<ll>(budget + 1, -1));

        return dfs(0, budget);
    }
};