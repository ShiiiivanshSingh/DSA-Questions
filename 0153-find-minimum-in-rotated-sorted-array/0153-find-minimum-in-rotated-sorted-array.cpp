class Solution {
public:
    int findMin(vector<int>& nums) {
    int num = nums[0]; 
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < num) {
            num = nums[i];
        }
    }
    return num;
}

};