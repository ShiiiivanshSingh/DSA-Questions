class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        stack<int> st;
        int x = INT_MIN;

        for(int i=n -1 ; i>=0;i--){
            if(nums[i] < x) return 1;
            while(!st.empty() && st.top() < nums[i]){
                x = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return 0;
    }
};