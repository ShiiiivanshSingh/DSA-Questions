class Solution {
public:
    int helper(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int maxi = 1;
        int cnt = 1;
        for(int i = 1;i<n;i++) {
            if(arr[i-1] + 1 == arr[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxSide = min(helper(hBars),helper(vBars));
        return (maxSide+1)*(maxSide+1);
    }
};