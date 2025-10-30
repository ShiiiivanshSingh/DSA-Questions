class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
    int n = price.size();
    int right = INT_MAX, left = 0;
    int ans = 0;
    sort(price.begin(), price.end());

    while(left<=right){
        int mid = left + (right-left)/2;
        int count =1, prev = price[0];
            for(int i = 1; i < price.size(); i++){
                if(price[i] - prev >= mid){
                    count++;
                    prev = price[i];
                }
            }
    
        if(count >=k) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid -1;
    }
    return ans;
    }
};