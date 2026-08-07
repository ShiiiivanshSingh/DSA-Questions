class Solution {
public:
    int myAtoi(string s) {
       
        int i=0,ans =0, sign = 1;
        
        while(s[i] == ' ')
            i++ ;            //whitespace > skipped
        
        
        if (s[i] == '-') {
            sign = -1;
            i++;                     //sign check
        } else if (s[i] == '+') 
            i++;
        
        
        while (isdigit(s[i])) {
        int di = s[i++] - '0';    // Handle overflow/underflow
         if (ans > (INT_MAX - di) / 10)       return (sign == 1) ? INT_MAX : INT_MIN;
         

        ans = ans * 10 + di;
        }   
        return ans * sign;
}
};