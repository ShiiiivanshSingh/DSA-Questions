class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        st.reserve(nums.size() * 2);
        for (int o : nums)  st.insert(o);

        for (int i : st) {

            if (!st.count(i - 1)) {
                int len = 1;
                int curr = i;
                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};