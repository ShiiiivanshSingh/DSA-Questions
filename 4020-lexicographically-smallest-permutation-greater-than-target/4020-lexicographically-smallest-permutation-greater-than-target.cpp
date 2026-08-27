class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);

        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++, freq[target[i] - 'a']--;

        for (int i = s.size() - 1; i >= 0; i--) {
            freq[target[i] - 'a']++;

            if (*min_element(freq.begin(), freq.end()) < 0)
                continue;


            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (freq[j]) {
                    freq[j]--;
                    string res = target.substr(0, i) + char('a' + j);
                    for (int k = 0; k < 26; k++)
                        res.append(freq[k], 'a' + k);
                    return res;
                }
                
            }

        }
        return "";
    }
};