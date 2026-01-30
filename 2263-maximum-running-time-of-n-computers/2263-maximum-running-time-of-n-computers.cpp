using ll = long long;
class Solution {
public:
    bool helper( vector<int>& batteries, int n, ll mid){
        long long need = n * mid;
        for (long long i =0;i<batteries.size();i++){
        
            need -=  min((ll)batteries[i] , mid);
            if(need<=0) return 1;
        }
        return 0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll ans = 0;
        ll max_time = 0;
        sort(batteries.begin() , batteries.end());
        for(int i=0; i<batteries.size();i++){
            max_time += batteries[i];
        }
        ll low = 0, high = max_time/n;
        while(high >=low){
            ll mid = low + (high - low)/2;
            if(helper(batteries, n ,mid)){
                ans = mid;
                low = mid+1;
            } else high = mid -1;
        } 
        return ans;
    }
};