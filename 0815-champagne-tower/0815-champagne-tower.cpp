class Solution {
public:
    double t[101][101];
        double idk(double i){
        return (i-1)/2.0;
    }

    double drake(int pour, int i, int j){
        if(i<j || i<0 || j<0) return 0.0;
          if(i == 0 && j ==0) return pour;


        if(t[i][j] != -1) return t[i][j];
        double wop1 = idk(drake(pour,i-1,j-1)); //right
        double wop2 = idk(drake(pour,i-1,j)); //left
        if(wop1<0) wop1=0;
        if(wop2<0) wop2=0;
        double bop = wop1 + wop2;
        return t[i][j] = bop;






    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
            t[i][j] = -1;
            }
        }
        return min(1.0,drake(poured, query_row,query_glass));
    }
};

// class Solution {
// public:
//        double meow[100][100];
//     double idk(double i){
//         return (i-1)/2.0;
//     }
//     double drake(double i, double j){
//         if(i<j || i<0 || j<0) return 0.0;
//         if(i == 0 || j ==0) return 
//         if(t[i][j] != -1) return t[i][j];
//         double wop1 = idk(drake(i-1,j-1)); //right
//         double wop2 = idk(drake(i-1,j)); //left
//         if(wop1<0) wop1=0;
//         if(wop2<0) wop2=0;
//         double bop = wop1 + wop2;
//         if(bop > 1.0) bop =1.0;
//         return t[i][j] = bop;
//     }
//     double champagneTower(double poured, double query_row, double query_glass) 
// };