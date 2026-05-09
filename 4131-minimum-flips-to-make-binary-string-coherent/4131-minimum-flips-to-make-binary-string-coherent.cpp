class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        int one =0;
        for(char i: s) if(i == '1') one++;
       
        int ans = min(one , n-one);
        if(one>=1) ans = min(ans, one -1);

        
        if(n >=2){
            int cost = one - (s[0] == '1') - (s[n-1] == '1');
            ans = min(cost, ans);
        }
        // int zero =0;
        // for(char i: s) if(i == '0') zero++;
        // l=0;
        
        // for(int i=0;i<=n;i++){
        //     ans = min(ans, l + zero);
        //     if(i<n){
        //         if(s[i] == '1') l++;
        //         else zero--;
        //     }
        // }
        return ans;
    }
};