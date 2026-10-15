// Last updated: 10/15/2026, 12:41:07 PM
class Solution {
public:
    int maxDistance(string moves) {
        int up =0 ,down =0, right =0, left =0, fail =0;

        for(char c: moves){
            if(c == 'U') up++;
            else if(c == 'D') down++;
            else if(c == 'L') left++;
            else if(c == 'R') right++;
            else if(c == '_') fail++;
        }

        int k = abs(up-down);
        int k2 = abs(left - right);
        return k + k2 + fail;
    }
};