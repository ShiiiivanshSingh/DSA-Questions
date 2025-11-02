
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
       
        long long d1 = d[0] , d2 = d[1] , r1=r[0] ,r2 = r[1];
        auto okhai = [&](long long t) -> bool{
            long long a1= t - t/r1;
            long long a2= t - t/r2;
            long long g= gcd((long long)r1, (long long)r2);
            long long l = r1/g * r2;
            long long both = t / l;
            long long can_use = t - both;



            return a1>=d1 && a2 >=d2 && can_use >= d1+ d2;
        };
        long long low =0, high =1;
        while(!okhai(high)) high <<=1;

        while(low + 1 < high){
            long long mid = low + (high - low)/2;
            if(okhai(mid)) high = mid;
                else low = mid;
        }
        return high;
    }
};