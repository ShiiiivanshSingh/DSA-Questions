using ll = long long;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll count = 0;
        ll length = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0 || prices[i] != prices[i-1] - 1) {
                length = 1;
            } else {
                length++;
            }
            count += length;
        }
        
        return count;
    }
};