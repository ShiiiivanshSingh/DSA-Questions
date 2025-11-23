class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n>0){
            s.push_back(char('0' + (n & 1)));
             n >>=1 ;
        }
        reverse(s.begin() , s.end());

        int j = s.size();
        int ans = 0;

        for(int  i = 0 ;i<j/2;i++){
            int x = j - 1 - i;
            if(s[i] != s[x]) ans+=2;
        }
        return ans;
    }
};