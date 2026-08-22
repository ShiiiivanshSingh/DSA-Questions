class Solution {
public:
    bool checkDivisibility(int n) {
        int cur = n;
        int sum = 0, pro = 1;
        while (cur) {

            sum += cur % 10;
            pro*= cur% 10;
            cur /= 10;
        }
        return n % (sum + pro) == 0;
    }
};