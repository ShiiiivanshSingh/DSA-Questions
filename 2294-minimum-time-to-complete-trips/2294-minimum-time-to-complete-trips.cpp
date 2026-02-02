using ll = long long;
class Solution {
public:
    ll helper(ll mid ,vector<int>& time, int totalTrips){ // trip in mid time
        ll n=0;
        for(int i:time){
            n = n + (mid/i); //trip per bus
            if(n > totalTrips) break;
        }
        return n;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l =1;
        ll h = 1e15;
        ll mid;
        while(l<=h){
            mid = l +(h-l)/2;
            ll trips = helper(mid, time, totalTrips);

            if(trips < totalTrips ) l = mid +1;
            else h = mid -1;
        }
        return l;
    }
};