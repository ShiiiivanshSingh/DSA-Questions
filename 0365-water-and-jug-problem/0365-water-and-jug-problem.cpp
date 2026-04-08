class Solution {
public:

    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return 0;
        if (target == 0) return 1;
        if( target % __gcd(x, y) == 0) return 1;
        return 0;
    }
};