class Solution {
public:
    vector<string> removeAnagrams(vector<string>& billa) {
        vector<string> myau;
        string last = billa[0];
        sort(last.begin(), last.end());
        myau.push_back(billa[0]);
        for (int i = 0; i < billa.size(); i++){
            string str = billa[i];
            sort(str.begin(), str.end());
            if (last != str){
                myau.push_back(billa[i]);
                last = str;
            }
        }
        return myau;
    }
};