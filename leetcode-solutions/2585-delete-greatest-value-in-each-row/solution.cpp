// class Solution {
// public:
//     int deleteGreatestValue(vector<vector<int>>& grid) {
        
//     }
// };
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        for (auto& row : grid)
            sort(row.begin(), row.end());

        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int j = cols - 1; j >= 0; j--) {
            int mx = 0;

            for (int i = 0; i < rows; i++) {
                mx = max(mx, grid[i][j]);
            }

            ans += mx;
        }

        return ans;
    }
};
