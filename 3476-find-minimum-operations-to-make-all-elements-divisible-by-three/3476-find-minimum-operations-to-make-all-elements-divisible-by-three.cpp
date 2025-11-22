class Solution {
public:
int count = 0;
    int minimumOperations(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]% 3==0){
                continue;
            } else if(nums[i] % 3 ==1){
                nums[i] = nums[i] -1;
                
                count++;
                cout << count;
            } else if ( nums[i] % 3 ==2 ){
                nums[i] = nums[i] + 1;
                cout << count;
                count++;
            }
        }
        return count;
    }
};