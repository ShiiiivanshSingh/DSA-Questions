class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string meow,myau;
        vector<string> words;
        while(ss >> meow) words.push_back(meow);
        for(int i = words.size()-1;i>=0;i--){
            myau += words[i];
            if(i!=0) myau += " ";
        }
        return myau;
    }
};