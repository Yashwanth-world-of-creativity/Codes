
class Solution {
public:
    // Function to solve N-Queens problem
    void solve(int col, vector<string>& board, int n,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal,
               vector<vector<string>>& ans) {
        // If all queens are placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Iterate through all rows
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<string>> ans;

//     bool isSafe(int row, int col, vector<string>& board, int n) {

//         // check upper column
//         for(int i = 0; i < row; i++) {
//             if(board[i][col] == 'Q')
//                 return false;
//         }

//         // check upper left diagonal
//         for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if(board[i][j] == 'Q')
//                 return false;
//         }

//         // check upper right diagonal
//         for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//             if(board[i][j] == 'Q')
//                 return false;
//         }

//         return true;
//     }

//     void solve(int row, vector<string>& board, int n) {

//         if(row == n) {
//             ans.push_back(board);
//             return;
//         }

//         for(int col = 0; col < n; col++) {

//             if(isSafe(row, col, board, n)) {

//                 board[row][col] = 'Q';

//                 solve(row + 1, board, n);

//                 board[row][col] = '.';  // backtrack
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {

//         vector<string> board(n, string(n, '.'));

//         solve(0, board, n);

//         return ans;
//     }
// };
