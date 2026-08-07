class Solution {
public:
    int solve(int n) {
        if (n == 0)
            return 0;
        //   if (n == 1) return 1;
        int high = 1;
        while (high * 2 <= n)
            high = high * 2;
        int rem = n - high;
        int cost = 2 * high - 1;
        return cost - solve(rem);
    }
    int minimumOneBitOperations(int n) {
        // f(2^k + r) = f(2^k) - f(r)
        return solve(n);
    }
};