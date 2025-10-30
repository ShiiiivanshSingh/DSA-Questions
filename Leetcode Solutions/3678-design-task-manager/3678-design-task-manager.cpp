class TaskManager {
public:
// actual  manual  labour  but  its  brat  so  i  dont  mind
    unordered_map<int, pair<int,int>> mp;
    priority_queue<pair<pair<int,int>,int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &t: tasks){
            int taskie = t[0], id = t[1], priority = t[2];
            mp[id] = { taskie, priority};
            pq.push({{priority,id} , taskie}); 
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({{priority, taskId}, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto a = mp.find(taskId);
        if(a == mp.end()) return;
        int uid = a -> second.first;
        mp[taskId] = {uid, newPriority};
        pq.push({{newPriority, taskId}, uid});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto current = pq.top();
            int a = current.first.first, id = current.first.second, userID = current.second;
            pq.pop();

            if(mp.find(id) != mp.end() && mp[id].second == a){
                mp.erase(id);
                return userID;
            }
        }
        return -1; // :(
    }
};

