class Solution {
public:
    int climbStairs(int n) {
        
        int first=1 ,second=2;
        if(n ==0) return 0;
        if(n ==1) return 1;

        for(int i=3;i<=n; i++){
            int current = first + second;
            first = second;
            second = current;
        }
    return second;
    }
};