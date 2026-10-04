class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n +1,0);
        for (auto &b : bookings) {
            arr[b[0] -1] += b[2];
            arr[b[1]]-= b[2];
        }
        for (int i = 1; i<n;i++) arr[i] += arr[i - 1];

        return {arr.begin(),arr.end() - 1};
    }
};