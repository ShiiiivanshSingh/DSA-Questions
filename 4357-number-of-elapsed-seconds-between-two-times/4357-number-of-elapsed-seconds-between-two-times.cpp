class Solution {
public:
    int solve(string &s) {
        return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 +
               stoi(s.substr(6, 2));
    }

    int secondsBetweenTimes(string st, string et) {
        return solve(et) - solve(st);
    }
};