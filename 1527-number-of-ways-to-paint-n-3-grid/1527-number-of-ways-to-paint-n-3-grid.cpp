using ll = long long;
using cl  = const long;
constexpr int mod = 1'000'000'007;

class Solution {
public:
    int numOfWays(int n) {

    ll color2 = 6;  // 121, 131, 212, 232, 313, 323  <- current combos
    ll color3 = 6;  // 123, 132, 213, 231, 312, 321 <- combos left

    for (int i = 1; i < n; ++i) {
        ll nextColor2 = color2 * 3 + color3 * 2;
        ll nextColor3 = color2 * 2 + color3 * 2;
        color2 = nextColor2 % mod;
        color3 = nextColor3 % mod;
    }

    ll ans =(color2 + color3) % mod;
    // cout << ans << endl;
    return ans;
    }
};