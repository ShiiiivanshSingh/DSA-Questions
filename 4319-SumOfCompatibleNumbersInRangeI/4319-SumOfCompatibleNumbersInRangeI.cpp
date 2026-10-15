// Last updated: 10/15/2026, 12:41:15 PM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int l = 0 , p =max(1, n - k);
        for (int i =  p; i <= n + k; i++) {
            if ( (n & i) == 0)  l = l + i;
        }
        return l;
    }
};