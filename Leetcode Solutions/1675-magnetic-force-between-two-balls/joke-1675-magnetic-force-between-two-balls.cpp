class Solution {
public:
    //  leetcode X ricknmorty when????
    //  meow from Earth C-137
    bool allowed(vector<int>& position, int m, int distance){
        //check if yeh allowed hai?
        int summer  = 1;
        int last = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - last >= distance){
                summer++;
                last = position[i];
            }
            if(summer >= m) return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); 
        // b r a t  b i n a r y s e a r c h
        int morty = 1, rick = position.back() - position.front();
        int ricknmorty = 0;
        while(morty<=rick) {
        int mid = morty + (rick - morty)/2;
            if(allowed(position, m , mid)){
                ricknmorty = mid;
                morty = mid + 1;
            } else {
                rick = mid - 1;
            }
        }
        return ricknmorty;
    }
};