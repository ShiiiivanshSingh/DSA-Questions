using ll = long long;
class Solution {
public:
    int totalWaviness(int num1, int num2) {
       ll ans =0;
        for(int u = num1 ; u<=num2; u++){
            string s = to_string(u);
            int n = s.size();
            if(n<3) continue;

            for(int i  = 1 ; i+1 <n ; i++){
                if(s[i] > s[i-1] && s[i] > s[i+1]) ans++;
                else if(s[i] < s[i-1] && s[i] < s[i+1]) ans++;
            }
        }
        return ans;
    }
};