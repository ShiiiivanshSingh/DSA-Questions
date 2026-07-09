class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> root(n);
        vector<bool> ans;

        root[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                root[i] = root[i - 1];
            else
                root[i] = i;
        }

        for (auto &q : queries)
            ans.push_back(root[q[0]] == root[q[1]]);

        return ans;
    }
};