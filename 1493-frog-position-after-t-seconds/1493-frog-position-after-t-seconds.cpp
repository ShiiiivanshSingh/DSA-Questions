class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    int target;



    double dfs(int u, int t) {

        double ans = 0;
        vis[u] = 1;

        int child = 0;
        for (int v : g[u]) 
            if (!vis[v]) 
                child++;
        

        if (t == 0 || child == 0) 
            return u == target;
        


        for (int v : g[u]) 
            if (!vis[v]) 
                ans += dfs(v, t - 1);
            
        double kk = ans / child;

        return kk;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        this->target = target;


        g.resize(n + 1);
        vis.resize(n + 1);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return dfs(1, t);
    }
};