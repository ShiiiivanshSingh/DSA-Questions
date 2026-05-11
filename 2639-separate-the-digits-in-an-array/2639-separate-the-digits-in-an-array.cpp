class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0 ;i< nums.size();i++){
            string k =  to_string(nums[i]);
            for(char i : k) ans.push_back(i -  '0');
        }
   //     cout << k << endl;
        return ans;
    }
};