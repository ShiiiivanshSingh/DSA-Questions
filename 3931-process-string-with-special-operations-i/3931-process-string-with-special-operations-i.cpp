class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (auto p : s) {
            if (p == '*') {
                if (result.size()) result.pop_back();
                
            } 
            
            else if (p == '#')   result += result;
             else if (p == '%')    result = string(result.rbegin(), result.rend());
             else  result += p;
            
        }
        return result;
    }
};