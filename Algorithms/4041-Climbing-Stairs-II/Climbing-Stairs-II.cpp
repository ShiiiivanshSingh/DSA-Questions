class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> meow = costs;
        vector<int> myau(n+1, INT_MAX);

        myau[0] = 0;

        for(int i = 0; i< n;i++){
            for(int j =1; j<4;j++){
                int u = j+i;
                if(u<=n){
                    myau[u] = min(myau[u], myau[i] + costs[u-1] + j*j);

                }
            }
        }
return myau[n];
        
    }
};