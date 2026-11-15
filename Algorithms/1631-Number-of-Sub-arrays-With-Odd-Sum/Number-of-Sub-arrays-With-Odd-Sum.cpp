class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        long long o = 0, p = 0, n = a.size();
        for (int x : a) o += p ^= x & 1;
        return o * (n + 1 - o) % 1000000007;
    }
};