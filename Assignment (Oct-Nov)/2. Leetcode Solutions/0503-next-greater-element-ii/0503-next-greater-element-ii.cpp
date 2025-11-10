class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n   = nums.size();
        stack<int> st;
        vector<int> ans(n , -1);
        unordered_map<int , int> map;


        for(int i = 2*n-1 ; i>=0  ; i--){
            int index = i % n;

            while(!st.empty() && st.top() <= nums[index])   st.pop();
            if(i<n ) {
                if(!st.empty()){
                    ans[index ] = st.top();
                 }
            }
        
            // if(st.empty() ) map[nums[index]]  = -1;
            // else map[nums[index]] = st.top(); 
            st.push(nums[index]);
            
        }


        // for(int i : nums) ans.push_back(map[i]);
        return ans;
    }
};