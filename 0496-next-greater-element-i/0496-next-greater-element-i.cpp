class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int , int> map;

        for(int i = n-1 ; i>=0  ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty() ) map[nums2[i]]  = -1;

            else map[nums2[i]] = st.top();
            
            
            st.push(nums2[i]);
            
        }
        for(int i : nums1) ans.push_back(map[i]);
        return ans;
    }
};