class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string l; 
        for(string s  : words){
            int counter =0;
            for(int i=0 ;i<s.size();i++)  counter += weights[ (s[i] - 'a') ];
            l += ('a' + (25 - (counter % 26)));
        }
    return l;
    }
};