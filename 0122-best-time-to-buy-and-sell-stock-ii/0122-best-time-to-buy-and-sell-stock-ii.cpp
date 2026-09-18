
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int maxprof = 0;
        int n= prices.size();
        for(int i=0;i<n-1;i++){
            if(prices[i+1] > prices[i]){
                maxprof = maxprof + (prices[i+1] - prices[i]);
            }
        }
        return maxprof;
    }
};