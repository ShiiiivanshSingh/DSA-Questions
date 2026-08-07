class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, 0);
        stack<int> st;
        vis[0] = 1;
        st.push(0);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            for(int key : rooms[curr]){
                if(!vis[key] ){
                    vis[key ] = 1;
                    st.push(key);
                }
            }
        }
        for(bool i : vis)  if(!i) return 0;
        return 1;
    }
};