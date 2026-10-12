class Solution {
public:
    int hammingDistance(int x, int y) {
        int diifBits = x ^ y;
        int dis =0;
        while(diifBits){
            diifBits = diifBits & (diifBits-1);
            dis++;
        }
        return dis;
    }
};