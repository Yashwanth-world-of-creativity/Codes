class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1)
        return dp[n];

    dp[n]=solve(n-1,dp)+solve(n-2,dp);
    return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


// class Solution {
// public:
//     int fib(int n) {
//         if(n==0)
//         return 0;
//         if(n==1)
//         return 1;

//         vector<int>dp(n+1);
//         dp[0]=0;
//         dp[1]=1;
        
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int fib(int n) {

//         if(n <= 1)
//             return n;

//         int prev2 = 0;
//         int prev1 = 1;

//         for(int i = 2; i <= n; i++) {
//             int curr = prev1 + prev2;
//             prev2 = prev1;
//             prev1 = curr;
//         }

//         return prev1;
//     }
// };
