class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int curr = 0;
        for(int i=0;i<gain.size();i++){


            ans = ans + gain[i];

            // int now = gain[i];
            // int curr = gain[i] -gain[i-1];
            curr = max(ans, curr);
            cout  << " "<< curr<< " "<< ans << "\n";
        }
        return curr;
    }
};