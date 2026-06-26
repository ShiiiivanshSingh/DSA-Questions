class Solution {
public:
    using ll = long long;

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), cur = n;
        vector<int> occ(2 * n + 1);
        occ[n] = 1;
        ll ans = 0, sum = 0;

for (int x : nums) {
    if (x == target) {
        sum += occ[cur];
        occ[++cur]++;
    } else {
        sum -= occ[--cur];
        occ[cur]++;
    }
    ans += sum;
}
        return ans;
    }
};