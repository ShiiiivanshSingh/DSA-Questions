class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return 1;
        cout << bits[n-2]  << endl << bits[n-1]  << endl ;
        int i = 0; 
        while(i<n-1){
            if(bits[i] == 1)i+=2;
            else i+=1;
        }
        return i == n-1;
    }
};