class Solution {
public:
    int numberOfSpecialChars(string word) {
       set<char> x , y;
       int spec = 0;

        for(char c : word){
            if(islower(c))  x.insert(c);
            else   y.insert(c + 32);
        } 

        for(char c : x) spec+= y.count(c);

        return spec;
    }
};