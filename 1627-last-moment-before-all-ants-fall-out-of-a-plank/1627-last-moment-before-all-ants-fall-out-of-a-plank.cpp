class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time =0;
        for(int num : left){
            time = max(time , num);
        }
        for(int num : right){
            time = max(time ,n - num);
        }
        return time;
    }
};