class Solution {
public:

int start =0, len =0;

    void wess(string s,int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            if(right - left+ 1 > len) {
                len= right - left+ 1;
                start = left;
            }
            left--; right++;
        }
    }

    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
        wess(s, i,i);
        wess(s, i,i+1);
        }
        return s.substr(start,len);
        }
    };













        // int left = 0, right  =s.size()-1;

        // while(left<=right){
        //     if(s[left] == s[right]){
        //         left++;
        //         right--;
        //     }
        // }
        // return s;
