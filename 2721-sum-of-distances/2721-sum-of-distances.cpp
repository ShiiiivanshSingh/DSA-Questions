using ll = long long;
class Solution {
public:

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> sum_id, freq_id;

        // lr
        for (int i = 0; i < n; i++) {
            ll freq = freq_id[nums[i]];
            ll sum = sum_id[nums[i]];

            arr[i] += freq * i - sum;

            freq_id[nums[i]] += 1;
            sum_id[nums[i]] += i;
        }
        
        freq_id.clear();
        sum_id.clear();

        // rl
        for (int i = n - 1; i >= 0; i--) {
            ll freq = freq_id[nums[i]];
            ll sum = sum_id[nums[i]];

            arr[i] += sum - freq * i;

            freq_id[nums[i]] += 1;
            sum_id[nums[i]] += i;
        }
        return arr;
    }
};