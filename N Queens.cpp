#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int dupRow = row, dupCol = col;

        // Check upper diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;

        // Check left side
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;

        // Check lower diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    // Recursive function to solve the problem
    void solve(int col, vector<string>& board, vector<vector<int>>& ans, int n) {
        if (col == n) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'Q') {
                        temp.push_back(j + 1); // Store 1-based index
                        break;
                    }
                }
            }
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';        // Place queen
                solve(col + 1, board, ans, n); // Recur for next column
                board[row][col] = '.';       // Backtrack
            }
        }
    }

    // Function to generate all solutions for the N-Queens problem
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        sort(ans.begin(), ans.end()); // Sort solutions lexicographically
        return ans;
    }
};

