class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int f1 = INT_MAX, f2 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) f1 = min(f1, start1[i] + duration1[i]);
        

        for (int i = 0; i < start2.size(); i++) {
            f2 = min(f2, max(start2[i], f1) + duration2[i]);
        }
        return f2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);


        return min(land_water, water_land);
    }
};