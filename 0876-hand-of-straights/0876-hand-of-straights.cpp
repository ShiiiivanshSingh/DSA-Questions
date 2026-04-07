class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // bool possible = 0;
        if( hand.size() % groupSize != 0) return 0;
        multiset<int> ha(hand.begin() , hand.end());

        while( !ha.empty()){
            int first = *ha.begin();
            for(int i=0;i<groupSize;i++){
                auto x = ha.find( first  + i);
                if(x == ha.end()) return 0;
                ha.erase(x);
            }
        }
        return 1;
    }
};