class Solution {
public:
bool hasGroupsSizeX(vector<int>& deck) {
        int y = 0;
        unordered_map<int,int> mp;
        for (int x : deck) mp[x]++;
        for (auto [x, c] : mp)
            y = __gcd(y, c);

        return y > 1;
    }
};