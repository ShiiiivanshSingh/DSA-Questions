// i%a==0 || i%b ==0
// totaL = (x/a + x/b) - x/lcm(a,b)


class Solution {
public:
    using ll = long long;
    const ll mod = 1e9+7; 


    ll lc_m(ll a,ll b){
            return a/gcd(a,b)*b; // gcd*lcm= num1*num2 
        }

    // removed folowing due to bottleneck / tle:(  
    // say a = 29911, b = 37516   it willl give tle hece gcd methid is better
    // ll lc_m(ll a,ll b){
    //     ll count = max(a,b); 
    //     while(1){ 
    //         if(count%a==0 && count%b==0) return count; 
    //         count++; 
    //         } 
    //     }


//actual funtion here
    int nthMagicalNumber(int n, int a, int b) {
        
        ll lcm = lc_m(a,b); //lcm to avoid 2x counting
        ll low = min(a,b);
        ll high = 1LL* n * low; 
        // for self: 1LL-> to force the calculation in 64bit otherwise garbage vals

        while(low<high){ //binary search
        
            ll mid = (low+high)/2;
            ll count = (mid/a + mid/b) - mid/lcm; // totaL = (x/a + x/b) - x/lcm(a,b)

            if(count<n) low = mid+1;
            else high = mid;
        }
        return low % mod;
    }
};
