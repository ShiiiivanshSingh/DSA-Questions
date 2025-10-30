class Solution {
public:
    int sum(int n) {
        return n * (n + 1) / 2;
    }
    
    int totalMoney(int n) {
        int w = n / 7;
        int res = w * 28 + 7 * sum(w - 1);

        n -= w * 7;
        return res + sum(w + n) - sum(w);
    }
};