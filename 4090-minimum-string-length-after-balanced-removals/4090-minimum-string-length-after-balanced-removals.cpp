class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a =0 , b = 0;

        for(char i : s){
            if(i == 'a')a++;
            else b++;


            
        }
        return abs(a-b);
    }
};