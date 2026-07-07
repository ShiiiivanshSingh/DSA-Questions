using ll = long long;
class Solution {
public:
    long long sumAndMultiply(int n) {
        n = abs(n);
        ll x = 0; 
        ll sum = 0;
        string s = to_string(n);
        for(char c: s){
            if(c != '0'){
                x = x * 10 + ( c - '0');
                sum+=(c - '0');
            }
        }
        return x * sum;
    }
};