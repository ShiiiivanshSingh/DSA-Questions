class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
      //  unordered_map<char, char> seq = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
      unordered_map<char, char> seq = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (st.empty() || st.top() != seq[c])
                    return 0;
                st.pop();
            }
        }

        return st.empty();
    }
};
