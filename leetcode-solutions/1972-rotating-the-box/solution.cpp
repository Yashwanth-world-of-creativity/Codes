// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

//         int m = box.size();
//         int n = box[0].size();

//         vector<vector<char>> result(n, vector<char>(m));

//         // Transpose
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 result[i][j] = box[j][i];
//             }
//         }

//         // Reverse every row -> 90 degree rotation
//         for(vector<char>& row : result) {
//             reverse(begin(row), end(row));
//         }

//         // Apply gravity
//         for(int j = 0; j < m; j++) {

//             for(int i = n - 1; i >= 0; i--) {

//                 if(result[i][j] == '.') {

//                     int stoneRow = -1;

//                     for(int k = i - 1; k >= 0; k--) {

//                         if(result[k][j] == '*') {
//                             break;
//                         }
//                         else if(result[k][j] == '#') {
//                             stoneRow = k;
//                             break;
//                         }
//                     }

//                     if(stoneRow != -1) {
//                         result[i][j] = '#';
//                         result[stoneRow][j] = '.';
//                     }
//                 }
//             }
//         }

//         return result;
//     }
// };



// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

//         int m = boxGrid.size();
//         int n = boxGrid[0].size();

//         // Step 1: simulate gravity in original box
//         for(int i = 0; i < m; i++) {

//             int empty = n - 1;

//             for(int j = n - 1; j >= 0; j--) {

//                 if(boxGrid[i][j] == '*') {
//                     empty = j - 1;
//                 }

//                 else if(boxGrid[i][j] == '#') {
//                     swap(boxGrid[i][j], boxGrid[i][empty]);
//                     empty--;
//                 }
//             }
//         }

//         // Step 2: rotate 90 degree clockwise
//         vector<vector<char>> res(n, vector<char>(m));

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 res[j][m - 1 - i] = boxGrid[i][j];
//             }
//         }

//         return res;
//     }
// };

//op
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // reverse each row -> rotate 90 degree
        for(auto &row : result) {
            reverse(begin(row), end(row));
        }

        // gravity
        for(int j = 0; j < m; j++) {

            int empty = n - 1;

            for(int i = n - 1; i >= 0; i--) {

                if(result[i][j] == '*') {
                    empty = i - 1;
                }

                else if(result[i][j] == '#') {

                    swap(result[i][j], result[empty][j]);
                    empty--;
                }
            }
        }

        return result;
    }
};
