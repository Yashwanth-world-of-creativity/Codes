class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;

        const int MOD = 12345;

        vector<int> flat;

        // flatten grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flat.push_back(grid[i][j] % MOD);
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        // prefix
        for(int i = 1; i < size; i++){
            prefix[i] = (prefix[i-1] * flat[i-1]) % MOD;
        }

        // suffix
        for(int i = size-2; i >= 0; i--){
            suffix[i] = (suffix[i+1] * flat[i+1]) % MOD;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        // build answer
        for(int i = 0; i < size; i++){
            int val = (prefix[i] * suffix[i]) % MOD;
            ans[i / n][i % n] = val;
        }

        return ans;
    }
};
