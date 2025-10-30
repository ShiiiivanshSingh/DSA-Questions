class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a= cost[0];  //from 0
        int b = cost[1]; //from 1
        for(int  i =2; i<cost.size();i++){
            int current = cost[i] + min(a,b);
            a = b;
            b = current;
        }
        return min(a,b);
    }
};