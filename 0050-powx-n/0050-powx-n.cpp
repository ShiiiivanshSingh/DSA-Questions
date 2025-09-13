class Solution {
public:
    double myPow(double x, int n) {
        long long num = n;
        if(num<0){
            x = 1/x;                // -ve situation handling >.<
            num = -num;
        }

        double answer = 1;

            while(num>0){
                if(num % 2 == 1) answer *= x;
                x *= x;
                num = num/2;
            }
        return answer;
    }
};