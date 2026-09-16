const int SEEDHE = 1000000007;

class Solution {
public:
    long long p(long long a,long long e) {
        long long r=1;
        while(e) {
            if(e&1) r=r*a%  SEEDHE;
            a=a*a%  SEEDHE;
            e>>=1;
        }
        return r;
    }

    int numberOfSets(int n,int k) {
        long long a=1 ,b=1;
        for(int i=1;i <=2*k ;i++)
            a=a*( n+k -i)%    SEEDHE,
            b=b* i %  SEEDHE;
        return a* p( b, 1000000005) %   SEEDHE;
    }
};