class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> adj(n);
    for (auto &e:invocations) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }
    vector<bool> seen(n, 0);
    vector<int> q;

    q.push_back(k);
    seen[k] = 1;
    int temp = 0;
    while (temp < q.size()) {
        int u = q[temp++];
        for (int v : adj[u]) {
            if (seen[v]) continue;
            seen[v] = 1;
            q.push_back(v);
        }
    }
    
    bool check = 1;
    for (auto &e:invocations) {
        int u = e[0], v = e[1];
        if (seen[u] || !seen[v]) continue; 
        check = 0;
        break;
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (check && seen[i]) continue;
        res.push_back(i);
    }
    return res;
}
};