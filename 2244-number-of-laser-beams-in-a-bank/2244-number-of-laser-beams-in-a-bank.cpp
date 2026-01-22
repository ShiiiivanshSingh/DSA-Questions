class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int current = 0, last =0  ,a =0;
        for(string i: bank){
            for (char j : i) {
                if(j == '1'){
                    current++;
                    a += last;
                }
            }

            if(current == 0)  continue;
                last = current;
                current  = 0;
        }
    return a;
    }
};