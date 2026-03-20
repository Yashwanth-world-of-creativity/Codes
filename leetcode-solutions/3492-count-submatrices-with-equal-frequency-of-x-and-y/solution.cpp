class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> colSum(n, 0);
        vector<int> colX(n, 0);

        int ans = 0;

        for(int i = 0; i < m; i++){
            int sum = 0, xCount = 0;

            for(int j = 0; j < n; j++){

                if(grid[i][j] == 'X'){
                    colSum[j] += 1;
                    colX[j] += 1;
                }
                else if(grid[i][j] == 'Y'){
                    colSum[j] -= 1;
                }

                sum += colSum[j];
                xCount += colX[j];

                if(sum == 0 && xCount > 0)
                    ans++;
            }
        }

        return ans;
    }
};
