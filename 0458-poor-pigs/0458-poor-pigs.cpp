class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempt = (minutesToTest) / minutesToDie;
        int pig =0;
        long long x = pow(attempt+1, pig);
        while(pow(attempt+1, pig)<buckets) pig++;
        return pig;
    }
};