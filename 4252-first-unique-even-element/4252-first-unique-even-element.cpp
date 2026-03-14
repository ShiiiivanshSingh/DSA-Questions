class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
     unordered_map<int,int>k;
        for(int l:nums) k[l]++;
        for(int i:nums){
            if(i % 2 == 0 && k[i] == 1) return i;
        }
        return -1;
    }
};