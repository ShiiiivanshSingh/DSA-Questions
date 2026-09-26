class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;//ator mbappe

        for (auto& k : knowledge)   dict[k[0]] = k[1];

        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {

                int j = s.find(')',i);
                string k = s.substr(i +1, j - i - 1);
                res += dict.count(k) ?  dict[k] : "?";

                i = j;
            } else   res += s[i];
            
        }
        return res;
    }
};