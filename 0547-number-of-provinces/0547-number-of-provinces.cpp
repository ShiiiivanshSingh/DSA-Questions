class Solution {
public:
void dfs(int w,vector<vector<int>>& isConnected, vector<int>&vis){
    vis[w] =1;
    int n = isConnected.size();
    for(int i = 0;i<n;i++){
        if(isConnected[w][i] == 1 && vis[i] ==0){
            dfs(i , isConnected, vis);
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i , isConnected, vis);
            }
        }
        return count;
    }
};