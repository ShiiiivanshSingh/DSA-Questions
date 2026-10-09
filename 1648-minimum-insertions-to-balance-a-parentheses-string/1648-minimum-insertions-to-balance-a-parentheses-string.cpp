class Solution {
public:
    int minInsertions(string s) {
        int res = 0, h = 0;

        for (char c: s) {
            if (c == '(') {
                if (h %2)   res++, h--;
                
                h = h+ 2;
            } else {
                h--;
                if (h <0)   res++, h = h + 2;
            }
        }
        return res+ h;
    }
};