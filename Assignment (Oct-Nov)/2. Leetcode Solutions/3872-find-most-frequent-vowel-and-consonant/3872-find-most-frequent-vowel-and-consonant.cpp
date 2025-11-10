class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> alpha(26,0);
        const string VOW = "aeiou";
        for(char c: s){
            alpha[c-'a']++;
        }
        int maxVow=0;
        int maxCon=0;
        for(int i=0;i<26;i++){
            char myau = i + 'a';
            if(VOW.find(myau) != string::npos){
                maxVow = max(maxVow, alpha[i]);
            }
            else {
                maxCon = max(maxCon , alpha[i]);
            }
        }
        return maxVow + maxCon;
    }
};