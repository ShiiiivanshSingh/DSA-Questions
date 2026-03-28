using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    ll abc(ll a, ll b){
        if(b == 0) return 1;
        ll res = abc(a * a % mod, b/2);
        if(b & 1) res = res * a % mod;
        return res;
        
    }        
    int countVisiblePeople(int n, int pos, int k) {
        ll a =1;
        for(int i=0;i<k;i++){
            a = a * (n - i -1) % mod;
            a = a * abc(i+1, mod -2) % mod;
        }
        return (2 * a) % mod;
    }
};