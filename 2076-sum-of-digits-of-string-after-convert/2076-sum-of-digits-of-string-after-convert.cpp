class Solution {
public:
    int getLucky(string s, int k) {
        int t = 0;
        for (char c : s) {
            int i = c - 'a' + 1;

            while (i) {

                t = t +  i % 10;
                i /= 10;
            }
        }

        k =  k -1;

        while (k--) {
            int cur = 0;


            while (t) {
                cur =  cur + t % 10;
                t = t / 10;

            }

            t = cur;
        }

        return t;
    }
};