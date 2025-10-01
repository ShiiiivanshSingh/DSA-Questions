// i%a==0 || i%b ==0
// totaL = (x/a + x/b) - x/lcm(a,b)
class Solution {
public:
    const long long mod = 1e9+7; // constraint


long long lc_m(long long a,long long b){
        return a/gcd(a,b)*b;
    }

    int nthMagicalNumber(int n, int a, int b) {
        
        long long lcm = lc_m(a,b); //lcm to avoid 2x counting
        long long low = min(a,b);
        long long high = 1LL* n * low;

        while(low<high){ //binary search
            long long mid = (low+high)/2;
            long long count = (mid/a + mid/b) - mid/lcm;

            if(count<n) low = mid+1;
            else high = mid;
        }
        return low % mod;
    }
};
