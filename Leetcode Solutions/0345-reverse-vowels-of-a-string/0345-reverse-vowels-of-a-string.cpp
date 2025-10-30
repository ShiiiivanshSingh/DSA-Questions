class Solution {
public:
bool vow(char c){
    string v = "aeiouAEIOU";
    return v.find(c) != string::npos;
}
    string reverseVowels(string s) {
      int left=0,right=s.size() -1;
      while(left<right){
        while(left<right && !vow(s[left])) left++;
        while(left<right && !vow(s[right])) right--;
        
      swap(s[left],s[right]);
      left++;
      right--;
      }
      return s;
    }
};