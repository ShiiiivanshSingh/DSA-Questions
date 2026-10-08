class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        vector<int> arr;
        for (char c : s) {
            if (!res.empty() && res.back() == c) 
                arr.push_back(arr.back() + 1);
            else 
                arr.push_back(1);


            res.push_back(c);
            
            if (arr.back() == k) {
                res.resize(res.size() - k);
                arr.resize(arr.size() - k);
            }
        }
        return res;
    }
};