class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n) {
            if ( (n & 3) == 3) 
                n++, ans++;
            else {
                ans += n & 1;
                n = n >> 1;
            }
        }
        return ans;
    }
};