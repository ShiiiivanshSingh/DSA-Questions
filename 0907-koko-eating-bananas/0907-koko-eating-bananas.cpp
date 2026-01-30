using ll = long long;
class Solution {
public:
    bool helper(vector<int>& piles, int h, int mid){
        ll hours =0;
        for(ll i=0; i<piles.size();i++){
            hours = hours + (piles[i] + mid -1  )/mid;
            // hours = hours + (i + mid -1  )/mid;
            if(hours > h) return 0; //cant eat
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin() , piles.end());
        int ans  =high;
        while(high >=low){
            int mid = low + (high -low)/2;
            if(helper(piles, h, mid)){
                ans = mid;
                high = mid-1;
            } else low = mid +1;
        }
        return ans;
    }
};