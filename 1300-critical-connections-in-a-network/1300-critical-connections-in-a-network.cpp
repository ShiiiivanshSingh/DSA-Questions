class Solution {
public:
    vector<vector<int>> ans;
    vector<int> time, low;
    vector<bool> vis;
    int timer = 0;
    void dfs(int x, int parent ,vector<vector<int>> &doc ){
        vis[x] =1;
        time[x] = low[x] = timer++;

        for (int v : doc[x]) {
            if (v == parent) continue;

            if (!vis[v]) {
                dfs(v, x, doc);
                low[x] = min(low[x], low[v]);

                if (low[v] > time[x]) {
                    ans.push_back({x, v});
                }
            } else {
                low[x] = min(low[x], time[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> doc(n);
        for (auto& e : connections) {
            doc[e[0]].push_back(e[1]);
            doc[e[1]].push_back(e[0]);
        }
        time.assign(n, -1);
        low.assign(n, -1);
        vis.assign(n, false);
        dfs(0 ,-1, doc);
        return ans;
    }
};

//brute->
// class Solution {
// public:
// void dfs(vector<bool> &vis,  vector<vector<int>> &doc, int a){
//     vis[a]=1;
//     for(int i : doc[a]){
//         if(!vis[i]){
//             dfs(vis, doc, i);
//         }
//     }
// }
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//     vector<vector<int>> ans;
    
//     for(int i=0 ; i<connections.size(); i++){
//         vector<vector<int>> doc(n);
//             for(int j=0 ; j<connections.size(); j++){
//                 if( i == j) continue;
//                 doc[connections[j][0]].push_back(connections[j][1]);
//                 doc[connections[j][1]].push_back(connections[j][0]);
//             }
//             vector<bool>vis(n,0);
//             dfs(vis, doc, 0); 
//             for(bool o: vis){
//                 if(!o){
//                     ans.push_back(connections[i]);
//                     break;
//                 }
//             }
//         }
//     return ans;
//     }
// };