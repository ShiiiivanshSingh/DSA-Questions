class Solution {
public:
    int digitFrequencyScore(int n) {
        int k =0;
        while(n){
            int k2 = n % 10;
            k = k + k2;
            n = n /10;
            
        }
        
        return k;
    }
};