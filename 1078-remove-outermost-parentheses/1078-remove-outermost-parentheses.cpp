class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string res;
        for(char c : s) {
            if(c == ')') level--;
            if(level) res += c;
            if(c == '(') level++;
        }

        return res;
    }
};