class Solution {
public:
int ans = INT_MAX;

    int earliestFinishTime(vector<int>& landStartTime,  vector<int>& landDuration, vector<int>& waterStartTime,  vector<int>& waterDuration) {


        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {

                int land = max(landStartTime[i] + landDuration[i],    waterStartTime[j]) + waterDuration[j];

                int water = max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i];


                ans = min(ans, min(land, water));
            }
        }

        return ans;
    }
};