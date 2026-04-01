class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        
        struct Robot {
            int pos, health, idx;
            char dir;
        };
        
        vector<Robot> robots;
        
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], i, directions[i]});
        }
        
        sort(robots.begin(), robots.end(), [](auto &a, auto &b){
            return a.pos < b.pos;
        });
        
        stack<Robot> st;
        
        for(auto &curr : robots){
            
            if(curr.dir == 'R'){
                st.push(curr);
            } else {
                
                while(!st.empty() && st.top().dir == 'R' && curr.health > 0){
                    
                    if(st.top().health < curr.health){
                        curr.health--;
                        st.pop();
                    }
                    else if(st.top().health > curr.health){
                        Robot top = st.top(); st.pop();
                        top.health--;
                        st.push(top);
                        curr.health = 0;
                    }
                    else{
                        st.pop();
                        curr.health = 0;
                    }
                }
                
                if(curr.health > 0){
                    st.push(curr);
                }
            }
        }
        
        vector<int> res(n, 0);
        
        while(!st.empty()){
            auto r = st.top(); st.pop();
            res[r.idx] = r.health;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(res[i] > 0) ans.push_back(res[i]);
        }
        
        return ans;
    }
};