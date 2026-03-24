class Solution {
public:
int ans =0;
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        for(auto &i : grid) mp[i]++;
        for(int i =0;i<n;i++){
            vector<int> col;
            for(int j =0;j<n;j++) col.push_back(grid[j][i]);   

            if(mp.count(col)) ans = ans + mp[col];
            
        }
        return ans;
    }
};