class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=1;i<s.size();i++){
            int k = s[i]  -  '0' , l = s[i-1] - '0';
            if(abs(k-l) > 2) return 0;
            
        }
        return 1;
    }
};