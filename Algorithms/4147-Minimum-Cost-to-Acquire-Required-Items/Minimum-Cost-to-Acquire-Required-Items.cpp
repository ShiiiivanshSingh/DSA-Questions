using ll = long long;

class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll m = min(need1, need2);
        ll both = min(costBoth, cost1 + cost2);
        return m * both + (ll)(need1 - m) * min(cost1, costBoth) + (ll)(need2 - m) * min(cost2, costBoth);
    }
};