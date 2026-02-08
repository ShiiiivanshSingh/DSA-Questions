class Solution {
public:
    int maxProfit(vector<int> &arr) {
        // code here
        int minprice = INT_MAX;
        int maxpro = 0;
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            
            minprice= min(minprice,arr[i]);
            int profit = arr[i]-minprice;
            maxpro = max(maxpro,profit);
            
        }
            return maxpro;
    }
};