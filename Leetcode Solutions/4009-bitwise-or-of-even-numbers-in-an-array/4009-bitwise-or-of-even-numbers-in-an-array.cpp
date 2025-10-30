class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> meow; //a|b
        int result = 0;
        for(int i: nums){
            if(i% 2 == 0) {
                result |=  i;

            }


        }
        return result;
    }
};