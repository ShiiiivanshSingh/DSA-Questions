class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int clockwise = 0, total =0;
        for (int i = start; i < destination; i++) clockwise += distance[i];
        for (int d : distance) total += d;
        return min(clockwise, total - clockwise);
        
    }
};