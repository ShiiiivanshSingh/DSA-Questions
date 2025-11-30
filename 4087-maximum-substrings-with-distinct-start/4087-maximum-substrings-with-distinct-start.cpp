class Solution {
public:
    int maxDistinct(string s) {
    return set(s.begin(),s.end()).size();        
    }
};