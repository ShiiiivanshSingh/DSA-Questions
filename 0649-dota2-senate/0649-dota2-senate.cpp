class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();

        for(int i =0;i<n;i++){
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        while(!radiant.empty() && !dire.empty()){
            int rad_pos = radiant.front();
            int dire_pos = dire.front();
            radiant.pop();
            dire.pop();

            if(rad_pos < dire_pos)  radiant.push(rad_pos + n);
            else dire.push(dire_pos + n);
        }
        if(dire.empty()) return "Radiant";
        else return "Dire";

    }
};