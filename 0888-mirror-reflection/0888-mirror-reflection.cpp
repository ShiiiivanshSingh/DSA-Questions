class Solution {
public:

    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }

    int mirrorReflection(int p, int q) {

        int g=gcd(p,q);
        p=p/g;
        q=q/g;

        if(p%2==0 && q%2==1) return 2;
        if(p%2==1 && q%2==1) return 1;
        return 0;
    }
};