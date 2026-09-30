class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> a;
        int len = 0;
        for(char c : seq) {
            if(c == '(') {
                len++;  a.push_back(len % 2);
            } else {
                a.push_back(len % 2);   len--;
            }
        }
        return a;
    }
};