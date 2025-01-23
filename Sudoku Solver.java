class Solution {

    public static boolean isValid(char[][] board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    public boolean solveSudoku(char[][] board) {  // Change void to boolean here
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solveSudoku(board))  // This will now return a boolean
                                return true;
                            else
                                board[i][j] = '.';  // Backtrack
                        }
                    }
                    return false;  // If no valid number can be placed, return false
                }
            }
        }
        return true;  // Sudoku solved successfully
    }
}
