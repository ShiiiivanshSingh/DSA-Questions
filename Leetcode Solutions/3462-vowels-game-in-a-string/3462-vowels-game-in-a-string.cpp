class Solution {
public:
    bool doesAliceWin(string s) {
           const string MYAUUU = "aeiou";
           for(char c: s){
                if (MYAUUU.find(c) != string::npos){
                    return true;
                }
            }
            return false;         //poor bob
        }
};

        //justice4bob
