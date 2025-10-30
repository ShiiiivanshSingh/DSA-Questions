
class Solution {
public:
    void reverseString(vector<char>& s) {
        int seedhe = 0;
        int maut = s.size() - 1;
        while (seedhe < maut) {
            // swapp
            char temp = s[seedhe];
            s[seedhe] = s[maut];
            s[maut] = temp;
            seedhe++;
            maut--;
        }
    }
};