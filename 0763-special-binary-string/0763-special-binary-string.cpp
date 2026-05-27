class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == ""  ) return s;
        vector<string> ans;
        int move =0 , j=0;
        
        for(int i=0; i<s.size() ; i++){
            if(s[i] == '1')  move +=1;
            else move = move -1;

            if(move == 0) {
                string val = makeLargestSpecial(s.substr(j + 1, i - j - 1)) ;
                string temp = "1" + val + "0";
                ans.push_back(temp);
                j = i+1;
            }


        }
        sort(ans.begin(), ans.end(), greater<string>());
        string res = "";
        for(auto &i : ans) res = res +  i;
        return res;
    }
};