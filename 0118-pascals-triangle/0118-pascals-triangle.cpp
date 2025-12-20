class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        arr.push_back({1});
        if (numRows==1) return arr;
        arr.push_back({1,1});
        if(numRows==2) return arr;
        
        for(int i=1;i<numRows-1;i++){
            vector<int>occur;
            occur.push_back(1);
            for(int j=0;j<arr[i].size()-1;j++){
                occur.push_back(arr[i][j]+arr[i][j+1]);
            }
            occur.push_back(1);
            arr.push_back(occur);
        }
        return arr;
    }
};