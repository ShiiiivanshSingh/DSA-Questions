

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001);
        int passengers = 0;

        for(auto &t : trips) {
            arr[t[1]] += t[0];
            arr[t[2]] -= t[0];
        }

        for(int i = 0; i <= 1000; i++) {
            passengers += arr[i];
            if(passengers > capacity)
                return 0;
        }

        return 1;
    }
};