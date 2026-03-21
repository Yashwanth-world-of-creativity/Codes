class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int i = 0; i <= n - k; i++){
            for(int j = 0; j <= m - k; j++){

                vector<int> temp;

                // collect k*k elements
                for(int x = i; x < i + k; x++){
                    for(int y = j; y < j + k; y++){
                        temp.push_back(grid[x][y]);
                    }
                }

             if(temp.size() <= 1){
              ans[i][j] = 0;
              continue;
            }

                sort(temp.begin(), temp.end());

                int mini = INT_MAX;

               for(int t = 1; t < temp.size(); t++){
        if(temp[t] != temp[t-1])   // only distinct values
        mini = min(mini, temp[t] - temp[t-1]);
}
                if(mini == INT_MAX) mini = 0;
                ans[i][j] = mini;
            }
        }

        return ans;
    }
};
