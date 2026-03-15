class Solution {
public:
    int countCommas(int n) {
       int k =0;
        for(int i =1; i<=n;i++){
            int x = to_string(i).size();
            k += (x - 1)/3;
        }
        return k;
    }
};