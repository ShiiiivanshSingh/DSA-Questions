class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mindff = INT_MAX;
        vector<vector<int>> ans;

        for(int i=1; i< arr.size(); i++){
            mindff = min(mindff, arr[i]- arr[i-1]);
        }

        for(int i =1; i< arr.size(); i++){
            if(arr[i] - arr[i-1]== mindff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans ;

    }
};