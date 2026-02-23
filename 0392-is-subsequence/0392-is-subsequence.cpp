class Solution {
public:
    bool isSubsequence(string s, string t) {
        int  n = t.length();
        int  m = s.length();
        if(m == 0 || n ==0  && m ==0) return 1;
        if( n == 0 ) return 0;
        int left =0, right = n-1;
        for(int i=0;i<m;i++){
            while(left <= right){
                if(s[i] == t[left]){
                    left++;
                    i++;
                } else {
                    left++;
                }
                if(i == m) return 1;
            }
        }   
        return 0;
    }
};