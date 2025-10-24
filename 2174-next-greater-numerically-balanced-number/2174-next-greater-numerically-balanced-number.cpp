class Solution {
public:
    bool achaa(int x){
        int digi[10] = {0};
        while(x > 0){
            digi[x%10]++;
            x /= 10;
        }
        for(int i=0;i<=9;i++){
            if(digi[i] > 0){
                if(i != digi[i]){
                    return 0;
                }
            }
        }
        
        return 1;
    }
    int nextBeautifulNumber(int n) {
        int myau = n+1;

        while(achaa(myau) == 0) myau++;
        
        return myau;
    }
};