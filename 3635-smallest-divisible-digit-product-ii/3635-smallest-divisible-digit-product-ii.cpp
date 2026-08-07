class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long x = t;
        for (int i = 2; i <= 9; i++)  while (x % i == 0) x /= i;
        if (x > 1) 
            return "-1";

        int n = num.size(), p = n - 1;

        vector<long long> rem(n + 1);


        rem[0] = t;


        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                p = i;   break;
            }
            rem[i + 1] =   rem[i] / gcd(rem[i], 1LL * (num[i] - '0'));
        }

        if (rem[n] == 1) 
            return num;

        for (int i = p ;  i  >= 0;  i--) {
            while (++num[i] <=  '9') {
                long long  cur =  rem[i] / gcd(rem[i], 1LL * (num[i] -  '0'));
                int d = 9;
                for (int j = n - 1; j > i; j--) {
                    while (cur % d) d--;
                    cur /=  d;
                    num[j] =  '0' + d;
                }
                if (cur ==  1) 
                    return num;
            }
        }
        string ans;
        for (int i = 9; i > 1; i--)
            while (t % i == 0)
                ans += '0' + i, t /= i;
        ans += string(max(0, n + 1 - (int)ans.size()), '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};