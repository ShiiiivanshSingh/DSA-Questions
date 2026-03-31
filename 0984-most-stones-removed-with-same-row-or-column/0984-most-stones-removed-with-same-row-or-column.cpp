class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]= find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b) parent[a]=b;
    }

    int removeStones(vector<vector<int>>& stones) {
        int shift = 10001; // diff row n column nodes

        parent.resize(20002);
        unordered_set<int> nodes;
        int components = 0;

        for(int i=0;i<20002;i++) parent[i]=i;
        for(auto &s: stones){
            int r = s[0];
            int c = s[1] + shift;

            unite(r, c);

            nodes.insert(r);
            nodes.insert(c);
        }


        for(int x: nodes) if(find(x) == x) components++;
        

        return stones.size() - components;
    }
};