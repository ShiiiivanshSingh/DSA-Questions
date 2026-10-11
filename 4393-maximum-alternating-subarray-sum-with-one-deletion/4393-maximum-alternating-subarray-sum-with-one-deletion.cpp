using ll = long long;

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        ll N = -1e18, res = LLONG_MIN;
        ll f0 = N, f1 = N, g0 = N, g1 = N, p0 = N, p1 = N;
        for (ll x : nums) {
            ll a = max(x, f1 + x);
            ll b = f0 - x;
            ll c = max(p1 + x, g1 + x);
            ll d = max(p0 - x, g0 - x);
            p0 = f0; 
            p1 = f1;
            f0 = a; f1 = b; g0 = c; g1 = d;
            res = max({res, f0, f1, g0, g1});
        }
        return res;
    }
};