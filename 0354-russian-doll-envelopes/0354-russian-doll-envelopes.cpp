class Solution {
public:
    static bool check(vector<int>& a, vector<int>& b)  { 
    if (a[0] == b[0]) return a[1] > b[1];   
    return a[0] < b[0];    
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin() , envelopes.end(), check);
        vector<int> vals;
        for (int i = 0; i < envelopes.size(); i++) {
            int height = envelopes[i][1];
            auto lb = lower_bound(vals.begin(), vals.end(), height); // binary srch
            int pos = lb - vals.begin();
            if (pos == vals.size()) vals.push_back(height);
            else vals[pos] = height;

        }
    return vals.size();
    }
};
// LEGACY CODE (GIVES TLE AVIV)
// class Solution {
// public:
// // works oly if w1 < w2  AND  h1 < h2
// // both strictly increase.
//     static bool check(vector<int>& a, vector<int>& b)  { // comparator func
//     if (a[0] == b[0]) return a[1] > b[1];   // same width → height descending
//     return a[0] < b[0];    
//     // if widths are different
//     // widths are equal tb → height descending
//     }
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         int n = envelopes.size();
//         sort(envelopes.begin() , envelopes.end(), check);
//         vector<int> vals;
//         for(int i=0;i<n;i++){
//             int height = envelopes[i][1], pos = 0;
//             while (pos < vals.size() && vals[pos] < height) pos++;

            
//             if(pos == vals.size()) vals.push_back(height);
//             else vals[pos] = height;   
//         }
//         // for(int i : vals) cout << " height -> "  << i << endl;
//     return vals.size();
//     }
// };