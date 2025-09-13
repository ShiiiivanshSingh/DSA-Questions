class Solution {
public:
    bool isIsomorphic(string s, string t) {
    vector<int> seedhe(128);
    vector<int> maut(128);
    for(int i=0;i<s.length();i++){
        if(seedhe[s[i]] != maut[t[i]]) return 0;
        seedhe[s[i]] = i +1;
        maut[t[i]] = i +1;

    }
    return 1; 
    }
};