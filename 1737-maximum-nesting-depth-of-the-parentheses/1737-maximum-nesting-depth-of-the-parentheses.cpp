class Solution {
public:
    int maxDepth(string s) {
        int d =0;
        stack<int>st;
        for(char i: s){
            if(i =='(') st.push(i);
            else if (i == ')') st.pop();
            d = max(d, (int)st.size());
        }
        return d;

    }
};