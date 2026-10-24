class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        partial_sum(begin(days), end(days), begin(days));
        auto helper = [&](const string& s) {
            return days[stoi(s.substr(0, 2)) - 1] + stoi(s.substr(3)); };


        return max(0, min(helper(leaveAlice), helper(leaveBob)) - max(helper(arriveAlice), helper(arriveBob)) + 1);
    }
};