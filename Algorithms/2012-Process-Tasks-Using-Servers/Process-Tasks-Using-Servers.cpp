class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> busy;
        for (int i = 0; i < servers.size(); ++i) idle.emplace(servers[i], i);

        long long ts = 0;
        vector<int> ans;
        for (int i = 0; i < tasks.size(); ++i) {
            ts = max(ts, (long long)i);
            if (idle.empty()) ts = max(ts, get<0>(busy.top()));
            while (!busy.empty() && get<0>(busy.top()) <= ts) {
                auto [t, w, j] = busy.top();
                busy.pop();
                idle.emplace(w, j);
            }
            auto [w, j] = idle.top();
            idle.pop();
            ans.push_back(j);
            busy.emplace(ts + tasks[i], w, j);
        }
        return ans;
    }
};