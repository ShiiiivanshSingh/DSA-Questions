class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);

        for (int x : nums) cnt[x]++;

        for (int i = 1; i <= m; i++)
            for (int j = i * 2; j <= m; j += i)
                cnt[i] += cnt[j];

        for (int i = 1; i <= m; i++)
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;

        for (int i = m; i; i--)
            for (int j = i * 2; j <= m; j += i)
                cnt[i] -= cnt[j];

        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];

        vector<int> ans;
        for (auto q : queries)
            ans.push_back(lower_bound(cnt.begin(), cnt.end(), q + 1) - cnt.begin());

        return ans;
    }
};