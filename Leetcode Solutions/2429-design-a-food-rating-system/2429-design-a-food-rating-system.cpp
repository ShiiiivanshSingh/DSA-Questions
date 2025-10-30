class FoodRatings {
public:
    unordered_map<string, pair<string,int>> details;
    unordered_map<string, map<int, set<string>, greater<int>>> byCuisine;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size  = foods.size();
        for(int i=0;i<size;i++){
            details[foods[i]] = {cuisines[i] , ratings[i]};
            byCuisine[cuisines[i]][ratings[i]].insert(foods[i]); 
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &a = details[food];
        string &meow = a.first;
        int prev = a.second;
        auto &b = byCuisine[meow];
        auto c = b.find(prev);
        c-> second.erase(food);
        if(c->second.empty())   b.erase(c);
        b[newRating].insert(food);
        a.second = newRating; 
    }
    
    string highestRated(string cuisine) {
        auto &a = byCuisine[cuisine];
        auto b = a.begin();
        return *b->second.begin();
    }
};

