class Solution {
public:
    int maxOperations(string s) {
        int op =0;
        int zero = 0;
        int n =s.length();

        
       for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                zero++;        
            else if(i>0 && s[i-1] == '1'){
                op += zero;
            }
                
        }
    return op;
    }
};