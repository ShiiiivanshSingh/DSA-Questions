class Solution {
public:
    void dfs(vector<bool> &visited, vector<vector<int>> &graph, int i, int &count){
        visited[i] = 1;
        count++;
        for(int x : graph[i]){
            if(!visited[x]) 
                dfs(visited, graph, x , count);
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int ans =0;
        int n= row.size() /2;
        vector<vector<int>> graph(n);
        for(int i=0;i<2*n;i+=2){
            int c1= row[i]/2;  
            int c2= row[i+1]/2;

            if(c1 != c2){
                graph[c1].push_back(c2);
                graph[c2].push_back(c1);
            }
        }
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count =0;
                dfs(visited, graph, i , count);
                ans += count -1;
            }
        }
        return ans;
    }
};