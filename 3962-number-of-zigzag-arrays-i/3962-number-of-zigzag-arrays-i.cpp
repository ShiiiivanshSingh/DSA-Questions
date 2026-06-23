// class Solution {
// public:
//     using ll = long long;

//     int zigZagArrays(int n, int l, int r) {
//         ll ans = 0;
//         int m = r - l + 1;
//         ll mod = 1e9 + 7;

//         vector<ll> up(m + 1), down(m + 1);

//         for (int i = 1; i <= m; i++)
//             up[i] = i - 1, down[i] = m - i;

//         for (int len = 3; len <= n; len++) {
//             vector<ll> pre(m + 1), suf(m + 2);
//             vector<ll> nu(m + 1), nd(m + 1);

//             for (int i = 1; i <= m; i++)
//                 pre[i] = (pre[i - 1] + down[i]) % mod;

//             for (int i = m; i >= 1; i--)
//                 suf[i] = (suf[i + 1] + up[i]) % mod;

//             for (int i = 1; i <= m; i++)
//                 nu[i] = pre[i - 1], nd[i] = suf[i + 1];

//             up = nu;
//             down = nd;
//         }

//         for (int i = 1; i <= m; i++)
//             ans = (ans + up[i] + down[i]) % mod;

//         return ans;
//     }
// };
class Solution {
public:
    static const int mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m,1), down(m,1);
        vector<int> pre(m+1), suf(m+1);

        while(--n){
            for(int i=0;i<m;i++){
                pre[i+1]=(pre[i]+up[i])%mod;
                suf[i+1]=(suf[i]+down[i])%mod;
            }

            for(int i=0;i<m;i++){
                int a=(suf[m]-suf[i+1]+mod)%mod;
                int b=pre[i];

                up[i]=a;
                down[i]=b;
            }
        }

        int ans=0;
        for(int x:up) ans=(ans+x)%mod;
        for(int x:down) ans=(ans+x)%mod;

        return ans;
    }
};