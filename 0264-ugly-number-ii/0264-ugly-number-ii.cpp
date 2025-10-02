class Solution {
public:
    int nthUglyNumber(int n) {    
        vector<int> meow(n);
        meow[0]  = 1;
        int a =0, b =0, c =0;

        for(int i=1;i<n;i++){
            int next = min({meow[a]*2, meow[b]*3, meow[c]*5});
            meow[i] = next;

            if(next ==meow[a]*2) a++;
            if(next ==meow[b]*3) b++;
            if(next ==meow[c]*5) c++;
        }
        return meow[n-1];
    }
};