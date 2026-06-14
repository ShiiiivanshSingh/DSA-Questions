class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp, cnt;
            int max_v = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (mp[x]) {
                    cnt[mp[x]]--;
                    if (cnt[mp[x]] == 0)
                        cnt.erase(mp[x]);
                    
                }
                mp[x]++;
                cnt[mp[x]]++;
                max_v = max(max_v, mp[x]);
                if (mp.size() == 1 ||
                    cnt.size() == 2 && max_v % 2 == 0 && cnt.count(max_v / 2))
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};