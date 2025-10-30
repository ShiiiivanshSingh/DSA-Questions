class Solution {
public:

    string rotate(string s, int k) {
        
        int n = s.length();
        k = k % n;
        
        int i = 0;
        int j = n-1;

        while(i < j){
            swap(s[i++],s[j--]);
        }
        i = 0;
        j = k-1;
        
        while(i < j){
            swap(s[i++],s[j--]);
        }
        i = k;
        j = n-1;

        while(i < j){
            swap(s[i++],s[j--]);
        }

        return s;
    }

    string addNew(string s, int a) {

        int n = s.length();

        for (int i=1; i<n; i+=2) {

            int rem = ((s[i] - '0') + a) % 10;
            s[i] = rem + '0';
        }

        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        
        queue<string> q;
        q.push(s);
        string ans = s;
        unordered_set<string> set;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (set.count(curr)) {
                continue;
            }
            set.insert(curr);
            ans = min(ans, curr);

            string rot = rotate(curr, b);
            string add = addNew(curr, a);

            q.push(rot);
            q.push(add);
        }

        return ans;
    }
};