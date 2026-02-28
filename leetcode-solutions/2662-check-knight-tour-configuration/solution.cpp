// class Solution {
// public:
//     int n;
    
//     vector<pair<int,int>> directions = {
//         {2,1},{1,2},{-1,2},{-2,1},
//         {-2,-1},{-1,-2},{1,-2},{2,-1}
//     };
    
//     bool dfs(vector<vector<int>>& grid, int x, int y, int move) {
//         if(move == n*n - 1) 
//             return true;
        
//         for(auto &d : directions) {
//             int nx = x + d.first;
//             int ny = y + d.second;
            
//             if(nx >= 0 && ny >= 0 && nx < n && ny < n 
//                && grid[nx][ny] == move + 1) {
                
//                 if(dfs(grid, nx, ny, move + 1))
//                     return true;
//             }
//         }
        
//         return false; // backtrack
//     }
    
//     bool checkValidGrid(vector<vector<int>>& grid) {
//         n = grid.size();
        
//         if(grid[0][0] != 0) 
//             return false;
        
//         return dfs(grid, 0, 0, 0);
//     }
// };
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // Step 1: Knight must start from top-left corner
        if (grid[0][0] != 0)
            return false;
        
        // Step 2: Store position of each number
        vector<pair<int, int>> position(n * n);
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int value = grid[row][col];
                position[value] = {row, col};
            }
        }
        
        // Step 3: Verify each move
        for (int k = 1; k < n * n; k++) {
            
            int prevRow = position[k - 1].first;
            int prevCol = position[k - 1].second;
            
            int currRow = position[k].first;
            int currCol = position[k].second;
            
            int rowDiff = abs(prevRow - currRow);
            int colDiff = abs(prevCol - currCol);
            
            // Valid knight moves: (2,1) or (1,2)
            bool isKnightMove =
                (rowDiff == 2 && colDiff == 1) ||
                (rowDiff == 1 && colDiff == 2);
            
            if (!isKnightMove)
                return false;
        }
        
        return true;
    }
};
