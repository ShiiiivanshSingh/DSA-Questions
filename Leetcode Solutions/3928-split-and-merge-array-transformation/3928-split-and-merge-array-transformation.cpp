class Solution {
public:
///myauuuuu fam this cooontest evil ahh contest
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        queue<vector<int>> q;
        set<vector<int>> seen;
        
        q.push(nums1);
        seen.insert(nums1);
        
        if(nums1 == nums2) return 0;
        
        int ops = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            ops++;
            
            while(sz--) {
                vector<int> myau = q.front();
                q.pop();
                
                for(int left = 0; left < n; left++) {
                    for(int right = left; right < n; right++) {
                        vector<int> sub(myau.begin() + left, myau.begin() + right + 1);
                        vector<int> rem;
                        
                        for(int i = 0; i < left; i++) rem.push_back(myau[i]);
                        for(int i = right + 1; i < n; i++) rem.push_back(myau[i]);
                        
                        for(int pos = 0; pos <= rem.size(); pos++) {
                            vector<int> next;
                            
                            for(int i = 0; i < pos; i++) next.push_back(rem[i]);
                            for(int x : sub) next.push_back(x);
                            for(int i = pos; i < rem.size(); i++) next.push_back(rem[i]);
                            
                            if(next == nums2) return ops;
                            
                            if(seen.find(next) == seen.end()) {
                                seen.insert(next);
                                q.push(next);
                            }}}}}}
        
        return -1;
    }
};