class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int u = prices[0] + prices[1];
        if (u <= money)  return money - u;
        return money;
    }
};