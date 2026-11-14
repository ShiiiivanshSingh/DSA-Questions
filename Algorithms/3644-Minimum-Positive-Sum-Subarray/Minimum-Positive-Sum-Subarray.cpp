class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int ans = INT_MAX, n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i, s = 0; j < n && j - i < r; j++)
                if ((s += a[j]) > 0 && j - i + 1 >= l) ans = min(ans, s);
        return ans == INT_MAX ? -1 : ans;
    }
};