class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (n == 1) return 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }


        int stride = k + 1;


        vector<int> dist(n * stride, INT_MAX);


        priority_queue<
            pair<pair<int, int>, int>,
            vector<pair<pair<int, int>, int>>,
            greater<pair<pair<int, int>, int>>
        > pq;


        dist[0 * stride + 1] = 0;
        pq.push({{0, 0}, 1});

        while (!pq.empty()) {
            int cost = pq.top().first.first;
            int node = pq.top().first.second;
            int streak = pq.top().second;
            pq.pop();

            if (node == n - 1) return cost;


            if (cost > dist[node * stride + streak]) continue;

            for (auto& it : adj[node]) {
                int ngbr = it.first;
                int weight = it.second;

                int nstreak = (labels[node] == labels[ngbr]) ? (streak + 1) : 1;
                int ncost = cost + weight;

                if (nstreak <= k) {
                    int next_idx = ngbr * stride + nstreak;

                    if (ncost < dist[next_idx]) {
                        dist[next_idx] = ncost;
                        pq.push({{ncost, ngbr}, nstreak});
                    }
                }
            }
        }

        return -1;
    }
};