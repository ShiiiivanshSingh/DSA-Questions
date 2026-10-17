class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int rem=0;
        
        auto expect =heights;
        sort(expect.begin(),expect.end());  
       
        for(int i=0;i<heights.size();i++)
            if (heights[i] != expect[i]) rem++;
        return rem;
    }
};