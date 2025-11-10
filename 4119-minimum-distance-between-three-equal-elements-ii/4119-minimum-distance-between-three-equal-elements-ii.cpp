class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        // if(nums.size()<=3) return -1;
        
        unordered_map<int, vector<int>> pos;
            for(int i=0; i<nums.size(); i++) pos[nums[i]].push_back(i);
    //         for(auto &p : pos){
    // cout << p.first << ": ";
    // for(int idx : p.second) cout << idx << " ";
    // cout << endl;
    // }
        for(auto &[val, v] : pos){
            if(v.size()<3) continue;
            for(int  i = 0  ; i+2< v.size(); i++){
                int a = v[i];
                int b = v[i+1];
                int c = v[i+2];

                int nas  = abs(a - b) + abs(b - c) + abs(c -a);
                ans= min(nas , ans);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};