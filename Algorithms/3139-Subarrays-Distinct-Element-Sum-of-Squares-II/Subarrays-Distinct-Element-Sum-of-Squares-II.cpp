class Solution {
    static const long long MOD = 1000000007LL;
    int n;
    vector<long long> b1, b2;


    void upd(vector<long long>& b, int i, long long v) {
        v %= MOD;
        if (v < 0) v += MOD;
        for (; i <= n + 1; i += i & -i) b[i] = (b[i] + v) % MOD;
    }


    long long qry(vector<long long>& b, int i) {
        long long r = 0;
        for (; i > 0; i -= i & -i) r = (r + b[i]) % MOD;
        return r;
    }

    void rangeAdd(int l, int r, long long v) {
        upd(b1, l, v);
        upd(b1, r + 1, -v);
        upd(b2, l, v * (l - 1));
        upd(b2, r + 1, -v * r);
    }

    long long prefix(int x) {
        return ((qry(b1, x) * x - qry(b2, x)) % MOD + MOD) % MOD;
    }

    long long rangeSum(int l, int r) {
        return ((prefix(r) - prefix(l - 1)) % MOD + MOD) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        b1.assign(n + 2, 0);
        b2.assign(n + 2, 0);
        unordered_map<int, int> last;
        long long S = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            int p = -1;
            auto it = last.find(nums[j]);
            if (it != last.end()) p = it->second;
            long long sum = rangeSum(p + 2, j + 1);
            S = (S + 2 * sum + (j - p)) % MOD;
            rangeAdd(p + 2, j + 1, 1);
            last[nums[j]] = j;
            ans = (ans + S) % MOD;
        }
        return (int)ans;
    }
};