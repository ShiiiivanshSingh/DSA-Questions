class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int greed=0, cookie=0;

        while(greed<g.size() && cookie<s.size()){
            if(s[cookie]>= g[greed]){
            greed++; cookie++;
            }
            else cookie++;
            }
        return greed;
    }
};