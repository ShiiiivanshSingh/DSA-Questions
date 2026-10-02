
class Solution {
public:
    void xoxo(int n, int open, int close, string current, vector<string>& result) {
        if (open < n)  xoxo(n, open + 1, close, current + "(", result);
        if (close < open)  xoxo(n, open, close + 1, current + ")", result);
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        xoxo(n, 0, 0, "", result);
        return result;
    }
};