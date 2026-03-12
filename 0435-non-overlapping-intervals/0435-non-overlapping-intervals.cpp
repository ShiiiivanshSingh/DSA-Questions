class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end());

        int end = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0] < end){
                ans++;
                end = min(end , intervals[i][1]);
            }
            else end = intervals[i][1];
        }
        return ans;
    }
};