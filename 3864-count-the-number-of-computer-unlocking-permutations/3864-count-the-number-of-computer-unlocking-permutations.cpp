class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1'000'000'007;      

        int n = complexity.size();
        if (n == 0) return 0;              

        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i]) 
                return 0;
            ans = ans * i % MOD;           
        }
        return (int)ans;
    }
};
