class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n = a.size(), sum = 0, cur = 0;
        for (int x : a) sum += x;
        for (int i = 0; i < n; i++) cur += i * a[i];
        int ans = cur;
        
        for (int i = n - 1; i > 0; i--) {
            cur += sum - n * a[i];
            ans = max(ans, cur);

        }
        return ans;
    }
};