class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int final_gas =0, curr = 0, init =0, n =gas.size();
        for(int i=0;i<n;i++){
            int diff = gas[i] - cost[i];
            final_gas += diff;
            curr+= diff;
            if(curr<0){
                init = i+ 1;
                curr =0;
            }
        }
        if(final_gas>=0) return init;
        return -1;
    }
};