class Solution {
public:
    int ans = 0;
    void dfs(int col, int ld, int rd, int full) {
        if (col == full)   {
             ans++ ; return; 
        }
        
        int free = full & ~(col | ld | rd);

        while (free) {

            int bit = free & -free;

            free -= bit;

            dfs(col | bit,
                (ld | bit) << 1,
                (rd | bit) >> 1,
                full);
        }
    }

    int totalNQueens(int n) {
        int full = (1 << n) - 1;
        dfs(0, 0, 0, full);
        return ans;
    }
};