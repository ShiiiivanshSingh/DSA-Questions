using ll = long long;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        ll m1= mass;
        for(int a : asteroids){
            if(m1 < a) return 0;
            
            m1 += a;
        }
        return 1;
    }
};