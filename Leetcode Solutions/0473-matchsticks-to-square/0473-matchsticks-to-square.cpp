class Solution {
public:
    bool search(int i, vector<int>& matchsticks, vector<int> &meow,int side){
        if(i == matchsticks.size()) {
            return meow[0] == side && meow[1] == side && meow[2] == side && meow[3] == side;
        }

        for(int j=0;j<4;j++){
            if(meow[j] + matchsticks[i] <= side){
                if(j>0  && meow[j] == meow[j-1])    continue;
                meow[j] += matchsticks[i];
                if(search(i+1, matchsticks, meow, side))    return 1;
                meow[j] = meow[j]   - matchsticks[i];
            }   
        }
        return 0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 !=0) return 0;
        int side = total /4;
        sort(matchsticks.rbegin(), matchsticks.rend());  // reverse sort >.<
        if(matchsticks[0] > side) return 0;
        vector<int> meow(4,0);
        return search(0, matchsticks, meow, side);
    }
};