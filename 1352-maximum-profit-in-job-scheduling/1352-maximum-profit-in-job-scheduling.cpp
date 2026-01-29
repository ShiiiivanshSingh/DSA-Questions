class Solution {
public:
// weighted interval scheduling
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        vector<vector<int>> jobs;
        vector<int> dp(n);

        for(int i=0 ;i<n;i++) jobs.push_back({endTime[i], startTime[i] ,profit[i]});
        sort(jobs.begin(), jobs.end());

        dp[0] = jobs[0][2]; //profit entires

        for(int i=1 ;i<n;i++){
            int take = jobs[i][2];
            int left =0, right= i-1; int index = -1;
            while(left <= right){
                int mid = (left + right) /2;
                if(jobs[mid][0] <= jobs[i][1]){
                    index = mid;
                    left = mid + 1;
                } else right = mid -1;
            }
            if(index != -1)   take += dp[index];
            dp[i] = max(take, dp[i-1]);
        }
    return dp[n-1];
    }
};