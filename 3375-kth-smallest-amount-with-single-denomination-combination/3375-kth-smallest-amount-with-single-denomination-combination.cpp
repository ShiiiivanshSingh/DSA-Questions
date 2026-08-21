// class Solution {
// public:
//     ll findKthSmallest(vector<int>& coins, int k) {
//         ll x = 0;

//         while (k) {
//             x++;
//             for (int c : coins) {
//                 if (x % c == 0) {
//                     k--;
//                     break;
//                 }
//             }
//         }

//         return x;
//     }
// };
using ll = long long;
class Solution {
public:

    ll findKthSmallest(vector<int>& coins, int k) {
        auto check = [&](ll x) {
            ll cnt = 0;
            for (int i = 1; i < (1 << coins.size()); i++) {
                ll temp  = 1;
                int bits = 0;

                for (int j = 0; j< coins.size(); j++) {
                    if (i >> j & 1) {
                        bits++;
                        temp  = lcm(temp , (ll)coins[j]);
                        if (temp  > x) break;
                    }
                }


                if (temp  <= x)
                    cnt += (bits & 1 ? 1 : -1) * (x / temp );
            }

            return cnt >= k;
        };




        ll temp  = 1, r = 1LL * *min_element(coins.begin(), coins.end()) * k;


        while (temp  < r) {
            ll m = (temp  + r) / 2;
            if (check(m)) r = m;
            else temp  = m + 1;
        }

        return temp ;
    }
};