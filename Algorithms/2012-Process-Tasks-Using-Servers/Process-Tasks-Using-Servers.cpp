class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<long long>, 
        vector<vector<long long>>, 
        greater<vector<long long>>> free, busy; 
        for (int i = 0; i < servers.size(); ++i) {
            free.push(vector<long long>{servers[i], i});
        }
        vector<int> ans;
        long long time = 0;
        long long lastTask = 0;
        
        while(ans.size() < tasks.size()) {
            while(!busy.empty() && time>= busy.top()[0]) {
                vector<long long> top = busy.top();
                busy.pop();
                // cout << "free: " << top[0] << " " << top[1] << " " << top[2] << endl;
                free.push({top[1], top[2]});
            }
            while (!free.empty() && lastTask < tasks.size() && lastTask <= time) {
                vector<long long> top = free.top();
                free.pop();
                ans.push_back(top[1]);
                // cout << "busy: " << time + tasks[lastTask] << " " << top[0] << " " << top[1] << endl;
                busy.push({time + tasks[lastTask++], top[0], top[1]});
            }
            if (free.empty()) time = busy.top()[0];   // wait for next server to finish
            else time = lastTask;   
        }
        return ans;
    }
};