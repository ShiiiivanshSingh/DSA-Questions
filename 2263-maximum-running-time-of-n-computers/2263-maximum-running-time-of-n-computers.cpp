using ll = long long;
class Solution {
public:
    bool canHold(vector<int>& batteries, ll mid , int n){
        ll need  = n* mid;
        for (int b : batteries) {
            need -= min((long long)b, mid);
                if (need <= 0) return true;  
        }
        return 0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll ans = 0;
        ll max_time = 0 ; 
        sort(batteries.begin() , batteries.end());
        for(int  i =0; i< batteries.size() ; i++) max_time += batteries[i];

        ll low = 0, high = max_time/n;

        while(high >= low){
            ll mid =  low + (high - low)/2;

            if(canHold(batteries, mid ,n)){
                ans = mid;
                low = mid+1;
            } else high = mid - 1; 
        }
  return ans;
    }
};