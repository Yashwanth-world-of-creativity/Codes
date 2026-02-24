class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board);
         }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true;
                            
                                board[i][j] = '.'; // backtrack
                        }
                    }
                
                return false;
              }
            }   
    }
    return true;
} 
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
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
};


// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int row[9] = {0}, col[9] = {0}, box[9] = {0};

//     void solveSudoku(vector<vector<char>>& board) {
//         // Initialize bitmasks
//         for (int r = 0; r < 9; r++) {
//             for (int c = 0; c < 9; c++) {
//                 if (board[r][c] != '.') {
//                     int num = board[r][c] - '1';
//                     setBit(r, c, num);
//                 }
//             }
//         }
//         solve(board);
//     }

//     bool solve(vector<vector<char>>& board) {
//         int r = -1, c = -1, minOptions = 10;

//         // MRV: find cell with minimum possibilities
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] == '.') {
//                     int mask = getMask(i, j);
//                     int options = __builtin_popcount(mask);
//                     if (options < minOptions) {
//                         minOptions = options;
//                         r = i;
//                         c = j;
//                     }
//                 }
//             }
//         }

//         if (r == -1) return true; // solved

//         int mask = getMask(r, c);

//         while (mask) {
//             int bit = mask & -mask;        // pick lowest set bit
//             int num = __builtin_ctz(bit);  // convert bit → number (0-8)

//             board[r][c] = num + '1';
//             setBit(r, c, num);

//             if (solve(board)) return true;

//             // backtrack
//             clearBit(r, c, num);
//             board[r][c] = '.';

//             mask &= (mask - 1); // remove used bit
//         }
//         return false;
//     }

//     inline int getMask(int r, int c) {
//         int used = row[r] | col[c] | box[(r/3)*3 + c/3];
//         return (~used) & 0x1FF;  // only 9 bits
//     }

//     inline void setBit(int r, int c, int num) {
//         int bit = 1 << num;
//         row[r] |= bit;
//         col[c] |= bit;
//         box[(r/3)*3 + c/3] |= bit;
//     }

//     inline void clearBit(int r, int c, int num) {
//         int bit = ~(1 << num);
//         row[r] &= bit;
//         col[c] &= bit;
//         box[(r/3)*3 + c/3] &= bit;
//     }
// };


// class Solution {
// public:
//     int row[9] = {0};
//     int col[9] = {0};
//     int box[9] = {0};
//     vector<pair<int, int>> spaces;

//     bool backtrack(vector<vector<char>> &board, int i) {
//         if (i == spaces.size()) return true;

//         int r = spaces[i].first;
//         int c = spaces[i].second;
//         int b = 3*(r/3) + (c/3);

//         for (int x = 0; x < 9; x++) {
//             int mask = 1 << x;
    
//             if (!(row[r] & mask) && !(col[c] & mask) && !(box[b] & mask)) {
//                 board[r][c] = '1' + x;

//                 row[r] |= mask; col[c] |= mask; box[b] |= mask;
//                 if (backtrack(board, i+1)) return true;
//                 row[r] &= ~mask; col[c] &= ~mask; box[b] &= ~mask;
//             }
//         }

//         return false;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     int mask = 1 << (board[i][j] - '1');
//                     row[i] |= mask;
//                     col[j] |= mask;
//                     box[3*(i/3) + (j/3)] |= mask;
//                 } else {
//                     spaces.push_back({i, j});
//                 }
//             }
//         }

//         backtrack(board, 0);
//     }
// };

