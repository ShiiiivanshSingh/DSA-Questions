class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char c : num) {
            while(k && !s.empty() && c < s.back()) {
                s.pop_back();
                k--;
            }
            s += c;
        }

        while(k-- && !s.empty()) s.pop_back();

        int i = 0;
        while(i < s.size() && s[i] == '0') i++;
        s = s.substr(i);

        if(s.empty()) return "0";
        return s;
    }
};