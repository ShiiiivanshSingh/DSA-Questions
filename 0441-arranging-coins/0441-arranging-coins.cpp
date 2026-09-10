class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0 , curr =1;
        while( n >= curr){
            ans++;
            n = n - curr;
            curr++;
        }
        return ans;
    }
};