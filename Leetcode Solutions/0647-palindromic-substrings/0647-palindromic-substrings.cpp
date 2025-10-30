class Solution {
public:
    int ans =0;
    void myau(string s , int  left, int right){
        while( left >=0 && right< s.size() && (s[left] == s[right])){
            ans++;  left--;   right++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            myau(s, i , i);
            myau(s, i  , i+1);
        }
    return ans;
    }

};

