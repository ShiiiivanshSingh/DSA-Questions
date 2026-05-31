class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {

        vector<int> ans;
        vector<int> tally(nums.size() + 1);

        for (int x : nums)
            if (x <= nums.size()) 
                tally[x]++;


        for (int i = 0; i < nums.size();) {
            int mex = 0;
            while (tally[mex]) mex++;

            if (!mex) {
                ans.push_back(0);
                if (nums[i] <= nums.size()) tally[nums[i]]--;
                i++;
            }
            else {
                set<int> st;
                while (st.size() < mex) {
                    if (nums[i] <= nums.size()) tally[nums[i]]--;
                    if (nums[i] < mex) st.insert(nums[i]);
                    i++; // append
                }

                ans.push_back(mex);
            }
        }

        return ans;
    }
};