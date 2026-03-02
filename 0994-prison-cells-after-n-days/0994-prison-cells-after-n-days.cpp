class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if (n % 14 == 0) n = 14;
        else  n = n % 14;
        for (int j = 0; j < n; j++) {
            vector<int> temp(cells.size(), 0);
            for (int i = 1; i < cells.size() - 1; i++) {

                if (cells[i - 1] == cells[i + 1]) {
                    temp[i] = 1;
                }
            }
            cells = temp;
        }

        return cells;



        
    }
};