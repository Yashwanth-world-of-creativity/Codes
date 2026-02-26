class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int m = coins.size() + 1;
        int n = amount + 1;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize first row
        for(int j = 1; j < n; j++) {
            dp[0][j] = INT_MAX - 1;   // impossible with 0 coins
        }
        
        // Fill table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], 
                                   1 + dp[i][j - coins[i-1]]);
                }
            }
        }
        
        if(dp[m-1][n-1] == INT_MAX - 1)
            return -1;
        
        return dp[m-1][n-1];
    }
};
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, amount + 1);
        
//         dp[0] = 0;
        
//         for(int i = 1; i <= amount; i++) {
//             for(int coin : coins) {
//                 if(i - coin >= 0) {
//                     dp[i] = min(dp[i], 1 + dp[i - coin]);
//                 }
//             }
//         }
        
//         return (dp[amount] > amount) ? -1 : dp[amount];
//     }
// };
