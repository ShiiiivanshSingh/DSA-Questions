// class Solution {
// public:
//     using ll = long long;

//     long long maxTotalValue(vector<int>& a, int k) {
//         priority_queue<ll, vector<ll>, greater<ll>> pq;
//         int n = a.size();

//         for (xint i = 0; i < n; i++) {

//             int mn = a[i], mx = a[i];

//             for (int j = i; j < n; j++) {

//                 mn = min(mn, a[j]);
//                 mx = max(mx, a[j]);

//                 ll x = mx - mn;

//                 if (pq.size() < k)
//                     pq.push(x);
//                 else if (x > pq.top()) {
//                     pq.pop();
//                     pq.push(x);
//                 }
//             }
//         }

//         ll ans = 0;

class Solution {
public:
    using ll = long long;

    long long maxTotalValue(vector<int>& a, int k) {
        int n = a.size();
        int lg = 32 - __builtin_clz(n);

        vector<vector<int>> mx(n, vector<int>(lg));
        vector<vector<int>> mn(n, vector<int>(lg));

        for (int i = 0; i < n; i++)
            mx[i][0] = mn[i][0] = a[i];

        for (int j = 1; j < lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j-1))][j-1]);
                mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j-1))][j-1]);
            }
        }

        auto getmx = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(mx[l][j], mx[r - (1 << j) + 1][j]);
        };

        auto getmn = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(mn[l][j], mn[r - (1 << j) + 1][j]);
        };


        priority_queue<vector<int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({getmx(i, n-1) - getmn(i, n-1), i, n-1});
        ll ans = 0;
        while (k--) {
            auto x = pq.top();
            pq.pop();
            int val = x[0], l = x[1], r = x[2];
            ans += val;

            if (r > l)
                pq.push({getmx(l, r-1) - getmn(l, r-1), l, r-1});
        }
        return ans;
    }
};
//         while (!pq.empty()) {
//             ans += pq.top();
//             pq.pop();
//         }

//         return ans;
//     }
// };