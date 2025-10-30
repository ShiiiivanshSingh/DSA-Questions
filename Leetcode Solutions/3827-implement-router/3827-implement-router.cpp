class Router {
    int limit;
    queue<array<int,3>> meow;
    unordered_set<string> myauuu;
    unordered_map<int, vector<int>> mp;
    
    string key(int s,int d,int t){
        return to_string(s)+"_"+to_string(d)+"_"+to_string(t);
    }
    
public:
    Router(int memoryLimit){
        limit=memoryLimit;
    }
    
    bool addPacket(int s,int d,int t){
        string k=key(s,d,t);
        if(myauuu.count(k)) return false;
        if(meow.size()==limit){
            auto x=meow.front();meow.pop();
            myauuu.erase(key(x[0],x[1],x[2]));
            auto &v=mp[x[1]];
            v.erase(lower_bound(v.begin(),v.end(),x[2]));
        }
        meow.push({s,d,t});
        myauuu.insert(k);
        mp[d].push_back(t);
        return true;
    }
    
    vector<int> forwardPacket(){
        if(meow.empty()) return {};
        auto x=meow.front();meow.pop();
        myauuu.erase(key(x[0],x[1],x[2]));
        auto &v=mp[x[1]];
        v.erase(lower_bound(v.begin(),v.end(),x[2]));
        return {x[0],x[1],x[2]};
    }
    
    int getCount(int d,int l,int r){
        auto &v=mp[d];
        return upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
    }
};
