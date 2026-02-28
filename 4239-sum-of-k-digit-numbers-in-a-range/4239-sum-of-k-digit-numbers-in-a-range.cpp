using ll = long long;
int MOD = 1e9 + 7;
ll ans =0;

class Solution {
public:
    //m y a u
    ll helper(ll a, ll b){ // func to  exponenetation (a^b % MOD)
        ll r =1;
        a = a % MOD;
        while(b){
            if(b&1) r = r * a;

            r = r % MOD;
            a = a* a;
            a= a % MOD;
            b = b >> 1; 
        }
        return r;
    }


    
    int sumOfNumbers(int l, int r, int k) {
        ll count = r - l +1; 
        ll sum = r*(r+1)/2 - (l*(l-1))/2; // alowed sum
        sum = sum % MOD;
        if(sum<0) sum = sum + MOD;
        ans = sum;
        ans = ans * helper(count, k -1) % MOD; // sum * count^(n-1)
        ans = ans * ((helper(10,k)-1 + MOD) % MOD) % MOD; // gp sum fx 
        ans = ans * helper(9 , MOD - 2) % MOD; // modulo div simce MOD is prime
        return ans;
        
    }
};