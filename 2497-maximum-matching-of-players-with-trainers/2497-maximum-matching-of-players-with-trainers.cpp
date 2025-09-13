class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0, train=0;
        while(ans<players.size() && train<trainers.size()){
            if(trainers[train] >= players[ans]){
                ans++; train++;
            }
            else train++;
        }
        return ans;
    }
};