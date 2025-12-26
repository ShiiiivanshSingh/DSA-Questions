#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> stk;
        char op = '+';  // To store the previous operator
        long num = 0;   // To handle multi-digit numbers
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                if (op == '+') stk.push(num);
                else if (op == '-') stk.push(-num);
                else if (op == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                } else if (op == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }
                op = s[i];
                num = 0;
            }
        }
        
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};
