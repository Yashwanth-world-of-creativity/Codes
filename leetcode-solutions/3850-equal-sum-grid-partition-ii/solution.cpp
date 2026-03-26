class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for(int i = 0; i <= m-2; i++) {

            for(int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = top - bottom;

            if(diff == 0) return true;

            // boundary checks
            if(diff == (ll)grid[0][0]) return true;
            if(diff == (ll)grid[0][n-1]) return true;
            if(diff == (ll)grid[i][0]) return true;

            // internal elements
            if(i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        total = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // horizontal cuts
        if(checkHorCuts(grid)) return true;

        // reverse grid
        reverse(grid.begin(), grid.end());
        if(checkHorCuts(grid)) return true;

        // transpose grid
        vector<vector<int>> transposeGrid(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        // vertical cuts (as horizontal on transpose)
        if(checkHorCuts(transposeGrid)) return true;

        reverse(transposeGrid.begin(), transposeGrid.end());
        if(checkHorCuts(transposeGrid)) return true;

        return false;
    }
};
