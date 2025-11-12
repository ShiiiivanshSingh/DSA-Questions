class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater <int>> vas;


        for( int num : nums){
            vas.push(num);
            if(vas.size() > k) vas.pop();
        }
        return vas.top();
    }
};