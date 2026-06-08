class Solution {
public:
    using ll = long long;

    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        ll l = intervals[0][0], r = intervals[0][1], len = 0;




        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= r + 1)  r = max(r, (ll)intervals[i][1]);
            else {
                len += r - l + 1;
                l = intervals[i][0];
                r = intervals[i][1];
                
            }
        }

        len += r - l + 1;
        
        ll bulbs = (brightness + 2) / 3;
        return len * bulbs;
    }
};