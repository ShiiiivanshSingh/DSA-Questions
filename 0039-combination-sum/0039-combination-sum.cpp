class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int,int)> bt = [&](int i, int t) {
            if (t == 0) {
                ans.push_back(cur);
                return;
            }

            for (; i < candidates.size(); i++) {
                if (candidates[i] > t) continue;
                cur.push_back(candidates[i]);
                bt(i, t - candidates[i]);
                cur.pop_back();
            }
        };

        bt(0, target);
        return ans;
    }
};