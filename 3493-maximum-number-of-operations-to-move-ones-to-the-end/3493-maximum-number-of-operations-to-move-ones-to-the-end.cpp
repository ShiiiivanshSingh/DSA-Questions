class Solution {
public:
    int maxOperations(string s) {
        int ops = 0 ;
        int zero = 0;
        for(int i = 0 ; i<s.length() ;i++){
            if(s[i] ==  '1'){
                zero++;
            }
            else if( i>0 && s[i-1] == '1'  ){
                ops+=zero;
            }
        } 
         return ops;
    }
};