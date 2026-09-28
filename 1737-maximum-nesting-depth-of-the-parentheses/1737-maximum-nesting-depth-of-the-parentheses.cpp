class Solution {
public:
    int maxDepth(string s) {
        int d =0, op =0;
        // stack<int>st;
        // for(char i: s){
        //     if(i =='(') st.push(i);
        //     else if (i == ')') st.pop();
        //     d = max(d, (int)st.size());
        // }
        // return d;
        for(char i :s){
            if(i =='(') op++;
            else if (i == ')') op--;
        d = max(d, op);
        }
        return d;

    }
};