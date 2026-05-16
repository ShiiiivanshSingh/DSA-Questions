class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (a[m] < a[r]) {
                r = m;
            }
            else if (a[m] > a[r]) {
                l = m + 1;
            }
            else {
                r--;
            }
        }

        return a[r];
    }
};