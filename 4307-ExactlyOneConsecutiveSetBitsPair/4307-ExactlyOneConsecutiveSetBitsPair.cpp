// Last updated: 10/15/2026, 12:41:22 PM
class Solution {
public:
    bool consecutiveSetBits(int n) {              
        return __builtin_popcount(n & (n>>1) )==1 ;
    }
};