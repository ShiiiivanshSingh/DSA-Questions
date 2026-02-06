
class Solution {
public:
    void generateParenthesis(int n, int open, int close, string current, vector<string>& result) {
          if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
         if (open < n) {
            generateParenthesis(n, open + 1, close, current + "(", result);
        }
        
         if (close < open) {
            generateParenthesis(n, open, close + 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, 0, 0, "", result);
        return result;
    }
};