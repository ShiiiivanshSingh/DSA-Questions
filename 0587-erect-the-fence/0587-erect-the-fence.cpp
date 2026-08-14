class Solution {
public:
    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0]) *(c[1]- a[1]) - (b[1]- a[1]) * (c[0] -a[0] );
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        int n = trees.size();
        if (n <= 1)   return trees;

        vector<vector<int>> lower, upper;
        for (auto& p : trees) {         // lower hull
            while (lower.size() >= 2 &&
                   cross(lower[lower.size() - 2], lower.back(), p) < 0) lower.pop_back();
            
            lower.push_back(p);
        }


        for (int i = n -1; i>= 0; i--) {         // upper hull
            auto& p = trees[i];
            while (upper.size() >= 2 &&  cross(upper[upper.size() - 2],
                         upper.back(), p) < 0) upper.pop_back();
            
            upper.push_back(p);
        }

        set<vector<int>> st;
        for (auto& p : lower)   st.insert(p);
        for (auto& p : upper)  st.insert(p);
        vector<vector<int>>helo (st.begin(), st.end());

        return helo;
    }
};