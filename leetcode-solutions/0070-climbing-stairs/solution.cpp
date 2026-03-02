class Solution {
public:

    int solve(int n, vector<int>& dp) {
        
        if(n == 0) return 1;     // reached exactly
        if(n < 0) return 0;      // invalid
        
        if(dp[n] != -1)          // already computed
            return dp[n];
        
        int left = solve(n-1, dp);
        int right = solve(n-2, dp);
        
        return dp[n] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
        
//         if(n <= 2)
//             return n;
        
//         int prev2 = 1;   // ways to reach step 1
//         int prev1 = 2;   // ways to reach step 2
//         int curr;
        
//         for(int i = 3; i <= n; i++) {
//             curr = prev1 + prev2;
//             prev2 = prev1;
//             prev1 = curr;
//         }
        
//         return prev1;
//     }
// };
