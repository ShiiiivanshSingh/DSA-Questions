class Solution {
public:
    static bool helper(vector<int>& a, vector<int>& b) {
        if (a[1] - a[0] < b[1] - b[0]) {
            return 1;
        } else 
            return 0;
        
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), helper);

        int ans = 0;

        for (auto &i : tasks) {
            int x = ans + i[0];
            ans = max(x, i[1]);
        }

        return ans;
    }
};