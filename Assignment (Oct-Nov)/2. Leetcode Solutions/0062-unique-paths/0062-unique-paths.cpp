class Solution {
public:
      int meow[100][100];
    int myau(int i, int j,int m, int n){
  
        if(i>=m || j>=n) return 0;
        if(i == m-1 || j == n-1) return 1;
        if(meow[i][j] != -1) return meow[i][j];
        int right = myau(i,j+1,m,n);
        int down = myau(i+1,j,m,n);
        return meow[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        memset(meow, -1 ,sizeof(meow));
        return myau(0,0,m,n);
    }
};