class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int best = 10e7;
        int ans =-1;
        for(int i=0;i<n;i++){
            if(capacity[i] >= itemSize && capacity[i] < best){
                best = capacity[i];
                ans = i ;
            }
        }
        return ans;
    }
};