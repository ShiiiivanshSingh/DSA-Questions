using ll = long long;
class Solution {
public:
// static bool check(vector<int>& a, vector<int>& b)  { 
//     if (a[0] == b[0]) return a[1] > b[1];   
//     return a[0] < b[0];    
//     }

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int m = stations.size(); // max  stops
        if(startFuel >= target) return 0; // can reach
        if(stations.empty()) return -1; // early exit
        if(startFuel < stations[0][0]) return -1; // cant reach 1st station

       // sort(stations.begin() , stations.end(), check);
        //vector<vector<ll>> dp(m ,vector<ll>(n, 0));  

        vector<ll> dp(m + 1, 0);
        dp[0]= startFuel;

        for(int i=0;i<m;i++){
            for(int j =i; j >=0; j--){
                if(dp[j] >= stations[i][0]){
                    dp[j+1] = max(dp[j+1] ,dp[j] + (ll)stations[i][1]);
                }
            }
        }
        
        for(int i=0;i<=m;i++)
            if(dp[i] >= target) 
                return i;
        
        return -1;
    }
};