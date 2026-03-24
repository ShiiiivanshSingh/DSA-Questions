class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int curr = 0;
        for(int i=0;i<gain.size();i++){
            ans = ans + gain[i];

            curr = max(ans, curr);
            // cout  << " "<< curr<< " "<< ans << endl;
        }
        return curr;
    }
};