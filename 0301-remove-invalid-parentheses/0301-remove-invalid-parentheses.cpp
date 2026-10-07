class Solution {

    vector<string> ans;
    void remove(string s, int i,int j,char a,char b) {
        int ops = 0;


        for(int k = i; k < s.size(); k++) {
            if(s[k] == a) ops++;
            if(s[k] == b) ops--;

            if(ops < 0) {
                for(int x = j; x <= k; x++)   if(s[x] == b&& (x ==j || s[x-1]!= b))   remove(s.substr(0,x) + s.substr(x+1), k, x, a, b);
                return;
            }
        }



        reverse(s.begin(), s.end());
        if(a == '(')  remove(s, 0, 0, ')', '(');
        else   ans.push_back(s);
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        remove(s,  0,0,'(',')');
        return ans;
    }
};