class Solution {
public:
    int vowelConsonantScore(string s) {
        int a=0, con=0, v=0;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) v++;
            else if ((c >= '0' && c <= '9') || c == ' ') continue;
            else con++;
        }
       
                if(con>0) a = floor(v / con);
   
        return a;
    }
};