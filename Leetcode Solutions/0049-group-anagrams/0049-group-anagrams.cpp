class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> gg;
        for(string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            gg[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto &s: gg){
            ans.push_back(s.second);
        }
        return ans;
    }
};