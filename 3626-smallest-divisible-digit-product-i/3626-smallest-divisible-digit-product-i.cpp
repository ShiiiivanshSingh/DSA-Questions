class Solution {
public:
    int smallestNumber(int n, int t) {
        for (   ;    ; n++) {
            int x = n, p = 1;
            while (x) p *= x % 10, x /= 10;
            if (p % t == 0) 
                return n;
        }
    }
};