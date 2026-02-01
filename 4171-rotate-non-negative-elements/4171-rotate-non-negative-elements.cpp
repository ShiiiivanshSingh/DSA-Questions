class Solution {
public:
    void loop(vector<int>& nums, int k) {
        if (nums.empty()) return;

        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> arr;
        vector<int> idx;
        if(nums.size() == 1){
            return nums;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) {
                arr.push_back(nums[i]);
                idx.push_back(i);
                // cout << arr.back() << " is at " << idx.back()<< endl;
                 }
            }
        
        int c = arr.size();
        
        loop(arr, k);
     
        for(int j=0;j<c;j++){
                // cout << "before swap ->" << nums[idx[j]] << " is " << arr[j] <<endl;
                nums[idx[j]] = arr[j];
                // cout << "after swap ->" <<nums[idx[j]] << " is " << arr[j] <<endl;
            }
        return nums;
    }
};