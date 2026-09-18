class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0], max_profit = 0;
        for(int i=0;i<prices.size();i++){
            int curr_profit = prices[i] - curr;
            max_profit = max(max_profit, curr_profit);
            curr = min(curr, prices[i]);
        }

        return max_profit; 
    }
};