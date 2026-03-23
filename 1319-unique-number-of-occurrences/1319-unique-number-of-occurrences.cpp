class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>freq;
        set<int>s;
        for(int x: arr) freq[x]++;
        for(auto &i : freq){
            if(s.count(i.second)) return 0;
            s.insert(i.second);
        }
        return 1;
    }
};