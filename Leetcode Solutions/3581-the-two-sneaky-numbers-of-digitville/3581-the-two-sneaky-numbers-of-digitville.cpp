class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> snd;
        int freq[100] = {0};
        for(int i : nums){
            freq[i]++;
            cout << freq[i] << "\n";
            if(freq[i] == 2) {
                snd.push_back(i);
            }
        }

        
        return  snd;
    }
};