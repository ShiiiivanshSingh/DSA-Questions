class Solution {
public:
int mem[51][51];
    int meow(vector<int> &values, int i, int j){
      int hai = INT_MAX;
      if(j-i<2) return 0;
      if(mem[i][j] != -1) return mem[i][j];
        for(int k=i+1;k<j;k++){
            int ok = values[i]* values[j]*values[k] + meow(values, i ,k) + meow(values, k ,j);
            hai  =min(ok ,hai);
        }
    return mem[i][j] = hai;
    }

    int minScoreTriangulation(vector<int>& values) {
        int k = values.size()-1;
        memset(mem, -1, sizeof(mem));
        return meow(values , 0, k);
    }
};