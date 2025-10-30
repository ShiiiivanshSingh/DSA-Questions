class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> son;
        for(int i=1;i<=n/2;i++){
            son.push_back(i);
            son.push_back(-i);
        }   
        if(n%2 ==1 ) son.push_back(0);
        return son;
    }
};