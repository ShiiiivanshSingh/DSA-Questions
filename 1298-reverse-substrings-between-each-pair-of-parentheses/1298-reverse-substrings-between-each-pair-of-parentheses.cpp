class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;   string ans;
        for (char c : s) {
            if (c == '(') st.push(ans.size());
            else if (c == ')') {
                int i = st.top();
                st.pop();
                reverse(ans.begin() + i, ans.end());
            } else ans += c;
        }
        return ans;
    }
};