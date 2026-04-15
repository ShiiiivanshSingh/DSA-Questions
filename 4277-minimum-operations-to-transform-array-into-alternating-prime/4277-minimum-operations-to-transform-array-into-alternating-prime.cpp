class Solution {
public:
    static const int n = 300005;
    static bool tab[n];
    inline static void build_tab() {
        tab[0] = tab[1] = true;

        for (int i = 2; i * i < n; i++) {
            if (!tab[i]) {
                for (int j = i * i; j < n; j += i) {
                    tab[j] = 1;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        static bool isBuilt = 0;
        if (!isBuilt) {
            build_tab();
            isBuilt = 1;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            if (i % 2 == 1) {
                while (k < n && !tab[k]) {
                    k++;
                    ans++;
                }
            } else {
                while (k < n && tab[k]) {
                    k++;
                    ans++;
                }
            }
        }
        return ans;
    }
};


bool Solution::tab[Solution::n];