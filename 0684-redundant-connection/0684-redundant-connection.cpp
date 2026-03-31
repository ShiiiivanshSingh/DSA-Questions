class Solution {
public:
    vector<int>parent  , size;
    void init(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(parent[i ] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int a, int b){
        a =find(a);
        b = find(b);
        if(a == b) return 0;
        if(size[a] < size[b]){
            swap(a,b);
        }
        
        parent[b] =a;
        size[a] = size[a] + size[b];
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n + 1);

        for(auto &e: edges){
            int u=e[0], v=e[1];

            if(!unite(u,v)) return e; 
            
        }

        return {};
    }
};