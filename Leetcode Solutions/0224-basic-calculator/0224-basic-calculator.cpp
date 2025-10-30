#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0, number = 0, sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } 
            else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= stk.top(); stk.pop(); // Apply sign before '('
                result += stk.top(); stk.pop(); // Add previous result
            }
        }

        return result + sign * number;
    }
};
