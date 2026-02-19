class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans  =0, current  =1, last =0;
        // int left =0, right = n-1;

        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                current++;
            } else {
                ans += min(current  , last);
                last= current;
                current   = 1;
            }
        }
        int x = min(last , current);
        return x + ans;
    }
};