class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        sort(citations.rbegin() , citations.rend());
        int id =0;
        while(id < n && citations[id] > id){
            id++;
        }
        return id;
    }
};