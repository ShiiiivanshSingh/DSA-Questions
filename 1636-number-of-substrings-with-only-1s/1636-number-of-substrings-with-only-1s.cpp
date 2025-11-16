using ll = long long;
class Solution {
public:
    int numSub(string s) {
        const ll vass = 1e9 + 7;
        ll count = 0, ans = 0;

        for(char c : s) {
            if(c == '1') {
                count++;                   
                ans = (ans + count) % vass; 
            } else {
                count = 0;                
            }
        }

        return ans;
    }
};
