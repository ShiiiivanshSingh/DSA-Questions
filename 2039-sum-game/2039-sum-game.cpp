class Solution {
public:
    pair<int, int> get(string s) {
        int a = 0, q = 0;

        for (char c : s)
            if (c == '?')  q++;
            else  a += c - '0';


        return {a, q};
    }

    bool sumGame(string num) {
        int n = num.size();

        pair<int, int> a = get(num.substr(0,n / 2));
        pair<int, int> b = get(num.substr(n /2));

        if ((a.second + b.second)% 2)  return 1;
        
        return a.first - b.first != (b.second - a.second) * 9 / 2;
    }
};