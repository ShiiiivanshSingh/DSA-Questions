class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> events;
        for(auto & i : buildings){
            int l = i[0];
            int r = i[1];
            int h = i[2];

            events.push_back({l , -h}); //first point
            events.push_back({r , h}); // last
        }

        sort(events.begin(), events.end());
        multiset<int> heights;
        heights.insert(0);
        int last =0;

        for(auto & i : events){
            int  len = i.first; int h = i.second; // sweep!??


            if( h < 0) heights.insert( -h); // negative height
            else heights.erase(heights.find(h));

            int curr = *heights.rbegin();

            if(curr != last){
                ans.push_back({len, curr}); 
                last = curr;
            }
        }
        // heights.insert(h);
        // heights.erase(heights.find(h));
        // curr = *heights.rbegin();
        // if (curr != prev) {
        //     ans.push_back({x, curr});
        //     prev = curr;
        // }
        return ans;
    }
};