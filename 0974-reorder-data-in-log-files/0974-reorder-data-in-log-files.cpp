class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, ans;
        vector<pair<string, string>> letters;  
        
        for (auto s : logs) {
            
            int i = s.find(' ');
            
            if (isdigitsit(s[i + 1])) digits.push_back(s);
            else letters.push_back( {s.substr(i + 1),s.substr(0, i)});
        }
        
        
        
        sort(letters.begin(), letters.end());
        for (auto p : letters) ans.push_back(p.second+" " +p.first);
        for (auto s : digits) ans.push_back(s);

        return ans;
    }
};