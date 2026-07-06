class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) 
            return a[1] > b[1];
        return 
            a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, mx = 0;
        for (auto &v : intervals) {
            if (v[1] > mx) {
                ans++;
                mx = v[1];
            }
        }
        return ans;
    }
};