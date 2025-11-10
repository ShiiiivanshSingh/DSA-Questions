class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frequency;
        for(char c : s) frequency[c]++;
        int n= s.size();
        vector<string> myau(n+1);

        for(auto &i : frequency){
            myau[i.second].append(i.second, i.first);
        }

        string sol;
        for(int i=n;i>0;i--){
            sol = sol + myau[i];
        }
        return sol;
         
    }
};