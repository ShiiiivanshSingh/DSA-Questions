class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        vector<string> ans;
        vector<pair<int,int>> inte;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
                first[curr] = i;
            last[curr] = i;
        }

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1)  continue;
            int l = first[i],  r = last[i];
        
        bool valid = 1;
        for(int i = l; i<= r;i++){
            int x = s[i] - 'a';
            if (first[x] < l) {
                valid = 0; break;
            }
            else if(last[x] > r)   r = last[x];
            
        }
            if(valid) inte.push_back({l,r});
    }
        sort(inte.begin(), inte.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int prev = -1;

        for (auto [l, r] : inte) {
            if (prev < l) {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }
        return ans;
                // if (first[curr] < l) {

        // } else if (first[curr] >= l && last[curr] > r) {

        // } else
        //     (first[curr] < l) {}
    }
  // return ans;
};