class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t =INT_MIN;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &i: times) adj[i[0]].push_back({i[1], i[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[k] =0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [a,b] = pq.top();
            pq.pop();
            if(a > dist[b]) continue;
            for(auto [c,d] : adj[b]){
                if(a + d < dist[c]) {
                    dist[c] = a + d;
                    pq.push({dist[c], c});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            t =max(t, dist[i]);
        }
        return t;
        
    }
};