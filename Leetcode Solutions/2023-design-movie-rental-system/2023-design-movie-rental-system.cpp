#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    map<pair<int,int>, int> daamn;
    unordered_map<int, set<pair<int,int>>> inStock;
    set<tuple<int,int,int>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries){
            int s = e[0], m = e[1], brat = e[2];
            daamn[{s,m}] = brat;
            inStock[m].insert({brat,s});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!inStock.count(movie)) return res;
        for (auto &brat : inStock[movie]){
            res.push_back(brat.second);
            if (res.size() == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int brat = daamn[{shop,movie}];
        inStock[movie].erase({brat,shop});
        rented.insert({brat,shop,movie});
    }

    void drop(int shop, int movie) {
        int brat = daamn[{shop,movie}];
        rented.erase({brat,shop,movie});
        inStock[movie].insert({brat,shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &myau : rented){
            res.push_back({get<1>(myau), get<2>(myau)});
            if (res.size() == 5) break;
        }
        return res;
    }
};
