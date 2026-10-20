class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> desc(n), premax(n), sufmin(n);

        for(int i =1;i<n;i++)
            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);



        inclusive_scan(nums.begin(), nums.end(), premax.begin(),
                       [](int a, int b) { return max(a, b); });
        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(),
                       [](int a, int b) { return min(a, b); });


        vector<bool> cut(n, 1);
        for(int i = 1;i<n;i++)  cut[i] = premax[i - 1] <= sufmin[i];

        auto sortable = [&](int k) {
            for(int l =0;l <n; l += k) {
                int r = l +k- 1;
                if(!cut[l] || desc[r] - desc[l] + (nums[r] > nums[l]) > 1)
                    return 0;
            }

            return 1;
        };

        int ans = 0;
        for(int k =1;k <= n; k++)
            if(n % k == 0 && sortable(k)) ans += k;

        return ans;
    }
};