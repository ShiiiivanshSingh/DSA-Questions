class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;

        for (string curr : queries) {
            for (string s : dictionary) {

                int len = 0;


                for (int i = 0; i < curr.size(); i++) 
                    if (curr[i] != s[i]) len++;
                

                if (len <= 2) {
                    ans.push_back(curr);
                    break;
                }
            }
        }

        
        return ans;
    }
};