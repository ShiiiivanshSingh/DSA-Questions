class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        int l = to_string(low).size(), h = to_string(high).size();

        for (int i = l; i <= h; i++)
            for (int j = 0; j + i <= 9; j++) {
                int x = stoi(s.substr(j, i));
                if (x >= low && x <= high) ans.push_back(x);
            }

        return ans;
    }
};