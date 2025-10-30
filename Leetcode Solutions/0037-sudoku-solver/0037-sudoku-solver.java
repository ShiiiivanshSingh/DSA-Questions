class Solution {
    static boolean sadakuku(char[][] board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return sadakuku(board, row + 1, 0);
        if (board[row][col] != '.') return sadakuku(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (cope(board, row, col, c)) {
                board[row][col] = c;
                if (sadakuku(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    static boolean cope(char[][] board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) return false;
            if (board[i][col] == val) return false;
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == val) return false;
        }
        return true;
    }

    public void solveSudoku(char[][] board) {
        sadakuku(board, 0, 0);
    }
}
