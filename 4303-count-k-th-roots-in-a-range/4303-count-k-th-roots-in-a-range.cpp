class Solution {
public:
const double t = 1e-5;
    int countKthRoots(int l, int r, int k) {
        int a = ceil(pow(l,    1.0 / k));
        int b = floor(pow(r + t,    1.0 / k));

        return b - a + 1;
    }
};