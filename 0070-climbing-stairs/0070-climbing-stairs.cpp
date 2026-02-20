class Solution {
public:
    int climbStairs(int n) {
        int a =1, b =2;
        if(n==1) return 1;
        if(n==0) return 0;
        for(int i=3;i<=n;i++){
            int current = a +b;
            a= b ;
            b = current;
        }
        return b;
    }
};