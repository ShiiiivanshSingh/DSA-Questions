class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans =0;
        vector<int> freq(26), temp;
        for(char c: chars) freq[c - 'a']++;
        for(auto i: words){
            temp = freq;
            bool flag =1;
            for(char  c : i){
                if(temp[c- 'a']-- == 0) flag =0;
            }
            if(flag) ans += i.size();
            
        }
        return ans;
        
    }
};