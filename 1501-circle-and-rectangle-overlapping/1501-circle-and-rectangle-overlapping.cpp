class Solution {
public:
    bool checkOverlap(int r,int xc,int yc,int x1,int y1,int x2,int y2) {

        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){

                int dx=i-xc;
                int dy=j-yc;

                if(dx*dx+dy*dy<=r*r) return true;
            }
        }

        return false;
    }
};