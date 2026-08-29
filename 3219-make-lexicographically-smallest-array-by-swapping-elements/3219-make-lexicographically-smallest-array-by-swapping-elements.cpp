// class Solution {
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> c;
        for (int i = 0; i < n; i++) c.push_back({nums[i], i});
        sort(c.begin(), c.end());

        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && c[j].first - c[j-1].first <= limit) j++;
            vector<int> idx;
            for (int k = i; k < j; k++) idx.push_back(c[k].second);
            sort(idx.begin(), idx.end());
            for (int k = i; k < j; k++) nums[idx[k-i]] = c[k].first;
            i = j;
        }
        return nums;
    }
};
//         int n = nums.size();
//         vector<int> idx(n);
//         iota(idx.begin(), idx.end(), 0);


//         sort(idx.begin(), idx.end(), [&](int i, int j){ return nums[i] < nums[j]; });

//         vector<int> res = nums;
//         int j = 0;

//         for (int i = 1; i <= n; i++) {
//             if (i == n || nums[idx[i]] - nums[idx[i-1]] > limit) {
//                 vector<int> pos(idx.begin() + j, idx.begin() + i);
//                 sort(pos.begin(), pos.end());
//                 for (int k = 0; k < (int)pos.size(); k++)
//                     res[pos[k]] = nums[idx[j + k]];
//                 j = i;
//             }
//         }
//         return res;
//     }
// };