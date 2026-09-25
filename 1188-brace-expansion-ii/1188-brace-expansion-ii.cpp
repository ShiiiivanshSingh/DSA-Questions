class Solution {
    string s;
    int i;

    set<string> item() {
        if (s[i] == '{') {
            i++;
            set<string> r = expr();
            i++;
            return r;
        }
        return {string(1, s[i++])};
    }

    set<string> term() {
        set<string> r = {""};

        while (i < s.size() && (s[i] == '{' || isalpha(s[i]))) {
            set<string> t = item(), x;

            for (auto &a : r)
                for (auto &b : t)
                    x.insert(a + b);

            r = x;
        }
        return r;
    }

    set<string> expr() {
        set<string> r;

        while (1) {
            set<string> t = term();
            r.insert(t.begin(), t.end());

            if (i < s.size() && s[i] == ',')
                i++;
            else
                break;
        }
        return r;
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;
        set<string> r = expr();
        return vector<string>(r.begin(), r.end());
    }
};