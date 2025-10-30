class Solution {
public:
    string sortVowels(string s) {
        string myau;
        for(auto c: s){
            char d = tolower(c);
            if(d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' ){
                myau.push_back(c);
            }
        }
        
        sort(myau.begin(),myau.end());
        int j=0;
        
        for(int i=0;i<s.size();i++){
            char d = tolower(s[i]);
                if(d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' ){
                    s[i] = myau[j++];
                }
           }
           return s;   
        }
    };