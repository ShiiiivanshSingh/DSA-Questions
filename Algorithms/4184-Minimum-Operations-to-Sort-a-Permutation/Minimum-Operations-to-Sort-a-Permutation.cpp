class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size(), s = find(a.begin(), a.end(), 0) - a.begin();
        bool up =1,down = 1;
        for (int i =1;i<n;i++) {
            int v = a[(s +i) % n];
            if (v !=i) up = 0;
            if (v !=n-i) down = false;
        }
        if (up) return min(s, n-s+2);
        if (down) return min(n -s,s+2);
        return -1;
    }
};