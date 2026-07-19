class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int d = abs(start[0] - target[0]) +
                abs(start[1] - target[1]);
        return d % 2 == 0;
    }
};