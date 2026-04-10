using ll = long long;
class Solution {
public:
    long long appealSum(string s) {
        ll ans =0 , k =s.size();
      //  dp[0] = 0;
      //  map<ll , ll > freq;
     //   vector<vector<ll>> dp(k , vector<ll> (k ,0));
        vector<int> arr(26,-1);

     //   ll current =0;
        for(int i=0;i<k;i++){
            int c = s[i] - 'a';
            ans+= (ll)(i - arr[c]) * (k  - i);
         //   current += a;
            arr[c] = i;
            
            // for(int j=i;i<k;j++){
            //     string sub = s.substr(i, j - i + 1);
            //     set<char> st(sub.begin(), sub.end());
            //     current += st.size();


            // }
            // dp[i] -> appeal of substr i to j

        }
        return ans;
    }
};