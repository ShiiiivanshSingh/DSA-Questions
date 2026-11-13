class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        long long ans = 0, S = 0, P = 0;
        deque<int> dq;
        for (int l = 0, r = 0; r < n; r++) {
            long long v = nums[r], cnt = 1;
            while (!dq.empty() && nums[dq.back()] <= v) {
                int j = dq.back();
                dq.pop_back();
                int st = dq.empty() ? l : dq.back() + 1;
                S -= (long long)nums[j] * (j - st + 1);
                cnt += j - st + 1;
            }
            S += v * cnt;
            dq.push_back(r);
            P += v;
            while (S - P > k) {
                S -= nums[dq.front()];
                P -= nums[l];
                if (dq.front() == l) dq.pop_front();
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};