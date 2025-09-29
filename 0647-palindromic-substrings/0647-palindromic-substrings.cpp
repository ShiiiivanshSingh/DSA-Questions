class Solution {
public:
int count =0;
    void wess(string s,int left, int right){
            while(left>=0 && right<s.size() && s[left] == s[right]){
                count++;
                left--;
                right++;
            }}
    int countSubstrings(string s) {
        // vector<int> ss;
       
       for(int i=0;i<s.size();i++){
       wess(s, i,i);
       wess(s, i,i+1);
       }
        return count;

    }
};