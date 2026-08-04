class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> k;
        for(int i:nums) freq[i]++;
        for(int i=1;i<=nums.size();i++){
            if(freq[i] ==0) k.push_back(i);
        }
        return k;
    }
};