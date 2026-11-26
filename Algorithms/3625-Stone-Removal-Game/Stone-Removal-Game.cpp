class Solution {
public:
    bool canAliceWin(int n) {
        int k = 0;
        for (int t = 10; n >= t;  n = n - t--) k++;
        return k & 1;
    }
};