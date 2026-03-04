class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n); // because we need cost till n-1 element so
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

// class Solution {
// public:

//     int solve(vector<int>& cost, int n, vector<int>& dp){

//         if(n == 0) return cost[0];
//         if(n == 1) return cost[1];

//         if(dp[n] != -1)
//             return dp[n];

//         return dp[n] = cost[n] + min(solve(cost,n-1,dp), solve(cost,n-2,dp));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {

//         int n = cost.size();

//         vector<int> dp(n,-1);

//         return min(solve(cost,n-1,dp), solve(cost,n-2,dp));
//     }
// };



// class Solution {
// public:

//     int minCostClimbingStairs(vector<int>& cost) {

//         int prev2 = cost[0];
//         int prev1 = cost[1];

//         for(int i = 2; i < cost.size(); i++){

//             int curr = cost[i] + min(prev1, prev2);

//             prev2 = prev1;
//             prev1 = curr;
//         }

//         return min(prev1, prev2);
//     }
// };
