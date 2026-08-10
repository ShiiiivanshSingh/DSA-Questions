class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int case1 = 0, case2 = 0, case3 = 0;

        for (int i : stones) {
            int r = i % 3;
            if (r == 0)
                case1++;
            else if (r == 1)
                case2++;
            else
                case3++;
        }
        int hg = case2 - case3;
        hg = abs(hg);

        if (case1 % 2 == 0)
            return case2 && case3;
        
        return hg > 2;
    }
};