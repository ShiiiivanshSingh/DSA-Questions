class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for(int house: houses){
            int position = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
int left = (position == 0) ? INT_MAX : house - heaters[position - 1];
int right = (position == heaters.size()) ? INT_MAX : heaters[position] - house;

            int close= min(left,right);
            radius = max(close, radius);
        }
        return radius;
    }
};