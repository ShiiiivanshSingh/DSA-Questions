class Solution {
public:
    int racecar(int target) {
        set<pair<int,int>> visited;
        queue<tuple<int,int,int>> q;

        q.push({0, 1, 0});
        visited.insert({0, 1});
        while(!q.empty()){
            auto [pos, speed, ins] = q.front();
            q.pop();
            if( pos == target) return ins;
            // if(pos > target && speed > 0) 
            // if (nextPos <= 2 * target)
            pair<int,int> nextA = {pos + speed, speed * 2};
            pair<int,int> nextR = {pos, speed > 0 ? -1 : 1};
            if(abs(nextA.first) <= 2 * target &&   !visited.count(nextA)){
                visited.insert(nextA);
                q.push({nextA.first, nextA.second, ins+1});
            }
            if(!visited.count(nextR)){
                visited.insert(nextR);
                q.push({nextR.first, nextR.second, ins+1});
            }

        }
        return -1;
    }
};