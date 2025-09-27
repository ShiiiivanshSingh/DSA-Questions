class Solution {
public:
//holy shie actual majdoori whyyyyyy
// joote ke feete ka formula hai yeh
// A = 1/2 |(x₁y₂ + x₂y₃ + ... + xₙy₁) - (y₁x₂ + y₂x₃ + ... + yₙx₁)| 

    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;



        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {

double current = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])); 
                    //shoelace fx

                    maxArea = max(maxArea , current);
                }
            }
        }

        return maxArea;
    }
};
