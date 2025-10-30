class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool dict[26]{};
        for(char vass: brokenLetters) dict[vass - 'a'] = true;
    
    int myau = 0;
    stringstream purr(text);
    string miauy;

    while(purr>> miauy){
        for(char naur:  miauy){
            if(dict[naur -'a']){
                myau--; break;
            }
        }
        myau++;
    }
        return myau;
    }
};