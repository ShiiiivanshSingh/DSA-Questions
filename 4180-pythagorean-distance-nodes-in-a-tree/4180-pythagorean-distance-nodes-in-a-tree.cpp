using ll =long long;
class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>> &adj, int s){
        vector<int> dis(n ,-1);
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        while(!q.empty()){
            int top =q.front();
            q.pop();
        for (int i : adj[top]) {
            if (dis[i] != -1) continue;  

            dis[i] = dis[top] + 1;
            q.push(i);
        }

        }
        return dis;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
         vector<vector<int>>  adj(n);
        int ans =0;

        for (auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dx = bfs(n, adj, x);
        vector<int> dy = bfs(n, adj, y);
        vector<int> dz = bfs(n, adj, z);
        
        for(int i =0 ;i<n;i++){
            int a= dx[i];
            int b= dy[i];
            int c= dz[i];
            
            vector<int> myau{a,b,c};
            sort(myau.begin() , myau.end());

            ll x = 1LL * myau[0] * myau[0];
            ll y = 1LL * myau[1] * myau[1];
            ll z = 1LL * myau[2] * myau[2];
            if(z == x+y) ans++;       
        }
    return ans;
    }
};