class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (auto& v : matrix){
            int sum = 0;
            for (auto& n : v) sum += n;
            ans.push_back(sum);
        }
        return ans;
    }
};