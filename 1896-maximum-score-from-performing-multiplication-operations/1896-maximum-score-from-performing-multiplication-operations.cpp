class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int op, vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    if (op == m) return 0;

    if (dp[left][op] != -1) return dp[left][op];
    int right = n - 1 - (op - left);
    int takeLeft = nums[left] * multipliers[op] + solve(left + 1, op + 1, nums, multipliers);
    int takeRight = nums[right] * multipliers[op] + solve(left, op + 1, nums, multipliers);
    return dp[left][op] = max(takeLeft, takeRight);
} int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
  //  if (op == m)
    //    return 0;
    dp.assign(m + 1, vector<int>(m + 1, -1));

    return solve(0, 0, nums, multipliers);
}};