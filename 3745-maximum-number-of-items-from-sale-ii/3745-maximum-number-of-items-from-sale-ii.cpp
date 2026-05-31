using ll = long long;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        ll n = items.size(), small = LLONG_MAX;
        for(auto &i : items) small = min(small , (ll)i[1]);

        vector<ll> total(n+1, 0) , x(n+1, 0);

        for(auto &i: items) total[i[0]]++;

        for(int i=1;i<=n;i++)
                for(int j = i;j<=n;j+=i)
                    x[i] = x[i] + total[j];

        vector<pair<ll, int>> packs;
        for(auto & i :  items){
            int j = x[i[0]] - 1;
            if(j>0 && i[1]<2 * small){
                packs.push_back({i[1] , j});
            }
        }
        sort(packs.begin() , packs.end());

        ll ans =0, b = budget;
         for(auto &i: packs){
             ll take = min((ll)i.second, b/i.first);
             ans+= take * 2;
             b = b - take* i.first;
         }
        ans += b/small;
        return (int)ans;
    }
};