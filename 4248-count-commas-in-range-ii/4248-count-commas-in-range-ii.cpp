using ll = long long;
class Solution {
public:
    long long countCommas(long long n) {
        ll ans =0, start = 1000 , count = 1;
        while(start<= n){
            ll end = min(n,start * 1000 - 1);
            if(end > n) end = n;

            ll count2 = end - start + 1;

            ans = ans + count2 * count;

            count++;
            start= start * 1000;
        }
        return ans;
    }
};