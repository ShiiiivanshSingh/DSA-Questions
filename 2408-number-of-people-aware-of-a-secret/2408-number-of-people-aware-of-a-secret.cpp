class Solution {
public:
    static constexpr int ul = 1'000'000'007;
    int maad(long long k){
        k %= ul;
        if (k < 0)
             k += ul;
        return k;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> og(n);

        long long share = 0;
        og[0]  = 1;

        for(int i=1;i<n;i++){
            if(i-delay >=0){
                share +=  og[i - delay];
                share= maad(share);
            }
            if(i-forget>=0){
                share -= og[i-forget] ;
                share= maad(share);
            }
            og[i] = share;
        }
        long long myau= 0;
        for(int i = n-forget;i<n;i++){
            myau += og[i];
            myau=maad(myau);
        }
    return myau;
    }
};