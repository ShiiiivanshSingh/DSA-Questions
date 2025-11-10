class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> myau;

        for(int uwu : nums) myau[uwu]++;
        int sui= 0;
        for(auto &o: myau) sui= max(sui, o.second);
        int solution = 0;
        for(auto &o: myau){
             if(o.second == sui){
                solution += o.second;
            }
        }
        return solution;
    }
};