class Solution {
public:
    int dfs(int node, int blocked, vector<vector<int>>& graph) {        //int best 
        int best = 0 ;
        for(int i : graph[node]){
            if(i == blocked) continue;

            best = max(best, 1 + dfs(i, blocked, graph));
        }
        return best;
    }
    int maximumInvitations(vector<int>& favorite) {
                int n = favorite.size();

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)  graph[favorite[i]].push_back(i);
        

        int maxCycle = 0;
        int twoCycles = 0;
        vector<int> state(n, 0);
        for (int i = 0; i < n; i++) {
            if (state[i]) continue;
            int now = i;
            while (state[now] == 0) {
                state[now] = 1;
                now = favorite[now];
            }
            if (state[now] == 1) {
                int len = 1;
                int next = favorite[now];


                while (next != now) {
                    len++;
                    next = favorite[next];
                }
                maxCycle = max(maxCycle, len);
                if (len == 2) {
                    int a = now, b = favorite[now];

                    twoCycles += 2;
                    twoCycles += dfs(a, b, graph); // a->b
                    twoCycles += dfs(b, a, graph);//b->a
                }
            }

            now = i;

            while (state[now] == 1) {
                state[now] = 2;  now = favorite[now];
            }
        }

        return max(maxCycle, twoCycles);
    }
};