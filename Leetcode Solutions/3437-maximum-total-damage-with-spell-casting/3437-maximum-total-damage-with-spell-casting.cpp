class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> achaa;
        for (int p : power) achaa[p] += p;
        long long myau = 0;
        for (auto i = begin(achaa); auto& [num, final] : achaa) {
            auto it2 = achaa.lower_bound(num - 2), it1 = achaa.lower_bound(num);
            long long prev2 = it2-- == i ? 0 : it2 -> second;
            final = myau = max({myau, prev2 + final, it1 == i ? 0 : it1 -> second});
        }
        return myau;
    }
};