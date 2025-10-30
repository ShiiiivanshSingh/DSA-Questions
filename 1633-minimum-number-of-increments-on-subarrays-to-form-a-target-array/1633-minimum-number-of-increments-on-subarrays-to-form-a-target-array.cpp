class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n =  target.size();
        int ans =target.front();

        for(int i = 1;i<n;i++){
            if(target[i] > target[i- 1]){
                int diff = target[i] - target[i -1];
                ans= ans +  diff;
            }
        }
        return ans;


    }
};