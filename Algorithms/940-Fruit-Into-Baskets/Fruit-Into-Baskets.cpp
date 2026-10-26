class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int side = 0;
        for(int x :fruits) {
            map[x]++;
            if(map.size() >2) {
                map[fruits[side]]--;
                if(map[fruits[side]]==0) 
                    map.erase(fruits[side]);
                side++;
            }
        }

        return fruits.size()-side;
    }
};