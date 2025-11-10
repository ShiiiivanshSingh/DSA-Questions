class Solution {
    inline bool inc_op(const string &s) {
        return s.find('+') != string::npos;
    }
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int inc = 0;
        int dec = 0;
        for(const string &op : operations) {
            int &act = inc_op(op) ? inc : dec;
            ++act;
        }
        return inc - dec;
    }
};