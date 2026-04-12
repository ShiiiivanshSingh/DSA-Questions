using db = double;
class Solution {
public:
    double angle(db a, db b, db c) {
        db pi = acos(-1);
        return acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / pi;
    }
    vector<double> internalAngles(vector<int>& sides) {
        vector<db> ans;
        int a = sides[0] ,b =sides[1], c =sides[2];
        if (a + b <= c || b + c <= a || a + c <= b) return {};
        ans.push_back(angle(a,b,c));
        ans.push_back(angle(b,c,a));
        ans.push_back(angle(a,c,b));
        sort(ans.begin() , ans.end());
        return ans;


    }
};