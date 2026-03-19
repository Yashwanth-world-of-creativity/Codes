// class Solution {
// public:
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int m = grid.size(), n = grid[0].size();
//         int count = 0;

//         vector<vector<int>> prefix(m, vector<int>(n, 0));

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
                
//                 prefix[i][j] = grid[i][j];

//                 if(i > 0) prefix[i][j] += prefix[i-1][j];
//                 if(j > 0) prefix[i][j] += prefix[i][j-1];
//                 if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];

//                 if(prefix[i][j] <= k) count++;
//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i - 1 >= 0)
                    grid[i][j] += grid[i-1][j];

                if(j - 1 >= 0)
                    grid[i][j] += grid[i][j-1];

                if(i - 1 >= 0 && j - 1 >= 0)
                    grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};
