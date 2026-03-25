class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }

        if(total % 2 != 0) return false;

        long long curr = 0;

        // Horizontal cut
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                curr += grid[i][j];
            }
            if(curr * 2 == total) return true;
        }

        curr = 0;

        // Vertical cut
        for(int j = 0; j < n - 1; j++){
            for(int i = 0; i < m; i++){
                curr += grid[i][j];
            }
            if(curr * 2 == total) return true;
        }

        return false;
    }
};
