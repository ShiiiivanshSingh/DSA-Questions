class Solution {
public:


    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        // vector<vector<int>> buh;
     
        double new_dia =0;
        int new_ar =0;

        //   double sq = sqrt(num);
        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int area = l*w;
            double dia = sqrt(l*l + w*w);
            // dia = ( sqrt(l*l)*sqrt(w*w) );
            if(dia>new_dia || (dia == new_dia && area > new_ar)){
                new_dia = dia;
                new_ar = area;
            }
        }
        return new_ar;
    }
};