class Solution {
public:
    int m, n;
    int dp[801][801][3]; // dp[i][j][neu]

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        // Base case: reached destination
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neu > 0) return 0; // skip last cell if negative
            return coins[i][j];
        }

        // Out of bounds
        if (i >= m || j >= n) return INT_MIN / 2; // avoid overflow

        // Return cached result
        if (dp[i][j][neu] != INT_MIN / 2) return dp[i][j][neu];

        // Option 1: Take current cell
        int down  = solve(coins, i + 1, j, neu);
        int right = solve(coins, i, j + 1, neu);
        int take  = coins[i][j] + max(down, right);

        // Option 2: Skip current cell (only if negative and neu > 0)
        int skip = INT_MIN / 2;
        if (coins[i][j] < 0 && neu > 0) {
            int skipDown  = solve(coins, i + 1, j, neu - 1);
            int skipRight = solve(coins, i, j + 1, neu - 1);
            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        // Initialize dp with INT_MIN/2
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k <= 2; k++)
                    dp[i][j][k] = INT_MIN / 2;

        return solve(coins, 0, 0, 2);
    }
};
