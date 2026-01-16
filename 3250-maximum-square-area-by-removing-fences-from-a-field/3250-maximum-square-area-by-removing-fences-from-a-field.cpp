class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_map<int,bool> hDiff;
        int res = -1, mod = 1e9+7;
        int hl = hFences.size(), vl = vFences.size();
        for(int i=0;i<hl;i++){
            for(int j=i+1;j<hl;j++){
                hDiff[hFences[j] - hFences[i]] = true;
            }
        }
        for(int i=0;i<vl;i++){
            for(int j=i+1;j<vl;j++){
                int diff = vFences[j] - vFences[i];
                if(hDiff.find(diff) != hDiff.end()){
                    res = max(res, diff);
                }
            }
        }
        if(res == -1) return -1;
        return (res*1LL*res)%mod;
    }
};