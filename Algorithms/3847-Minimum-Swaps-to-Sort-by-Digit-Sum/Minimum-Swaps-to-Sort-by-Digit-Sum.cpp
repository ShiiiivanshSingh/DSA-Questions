class Solution {
public:
    int digitSum(int n) {
        int s = 0;
        while(n) s += n % 10, n /= 10;
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end(), [&](int x, int y) {
            if(digitSum(x) != digitSum(y))
                return digitSum(x) < digitSum(y);
            return x < y;
        });

        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++) pos[a[i]] = i;

        int ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int j = i, cnt = 0;
            while(!vis[j]) {
                vis[j] = 1;
                j = pos[nums[j]];
                cnt++;
            }
            ans += cnt - 1;
        }
        return ans;
    }
};