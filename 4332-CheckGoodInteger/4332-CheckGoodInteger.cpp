// Last updated: 10/15/2026, 12:41:08 PM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int a =0, b =0;
        while(n){
            int i = n % 10;
            a = a+ i;   b = b + (i*i);
            n =n /10;
        }
        if(b-a>=50) return 1;
        return 0;
    }
};