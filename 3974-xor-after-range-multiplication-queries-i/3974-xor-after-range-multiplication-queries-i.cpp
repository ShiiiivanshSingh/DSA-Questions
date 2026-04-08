using ll = long long;
const ll MOD = 1e9 + 7; 

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int ans = 0;
        for (auto &i : queries) {
            int l = i[0], r = i[1], k = i[2], v = i[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        for (auto x : nums) ans ^= x;
        return ans;
    }
};