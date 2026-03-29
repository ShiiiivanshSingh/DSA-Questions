class EventManager {
public:
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    EventManager(vector<vector<int>>& events) {
        for(auto &i : events){
            int x = i[0];
            int y = i[1];
            mp[x] = y;
            pq.push({y , -x});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int a = i.first;
            int b = -i.second;
            if(mp[b] == a){
                mp.erase(b);
                return b;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */