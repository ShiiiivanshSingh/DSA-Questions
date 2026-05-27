class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size(), ans = 0, x = 0;

        sort(satisfaction.begin(), satisfaction.end());

        if (satisfaction[n - 1] < 0) return 0;
        

        for (int i = n - 1; i >= 0; i--) {
            x += satisfaction[i];
            if (x < 0)  break;
            ans += x;
            
        }
        return ans;
    }
};