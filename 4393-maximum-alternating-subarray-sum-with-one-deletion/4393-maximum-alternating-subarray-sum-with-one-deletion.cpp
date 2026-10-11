using ll = long long;
class Solution {
public:
ll negreira = LLONG_MIN / 2;
ll ans = LLONG_MIN;
    ll maxAlternatingSum(vector<int>& nums) {
        ll f0 = negreira, f1 = negreira;
        ll g0 = negreira, g1 = negreira;
        ll p0 = negreira, p1 = negreira;

        for (ll x : nums) {
            ll a = max(x, f1 + x),b = f0 - x;

            ll c = max(p1 + x, g1 + x);
            ll d = max(p0 - x, g0 - x);

// suff-> ??
            p0 = f0;
            p1 = f1;

 // jank ->
            f0 = a;
            f1 = b;
            g0 = c;
            g1 = d;

            ans = max({ans, f0, f1, g0, g1});
        }

        return ans;
    }
};