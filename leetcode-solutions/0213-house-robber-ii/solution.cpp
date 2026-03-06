class Solution {
public:
    
    int solve(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = nums[start];

        for(int i = start+1; i <= end; i++){
            // int take = nums[i] + prev2;
            int take=nums[i];
            
            take+=prev2;

            int skip = prev1;
            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n-2);
        int case2 = solve(nums, 1, n-1);

        return max(case1, case2);
    }
};

// class Solution {
// public:

//     int solve(vector<int>& nums, int l, int r)
//     {
//         int take = 0, skip = 0;

//         for(int i = l; i <= r; i++)
//         {
//             int newTake = skip + nums[i];
//             skip = max(skip, take);
//             take = newTake;
//         }

//         return max(take, skip);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1)
//             return nums[0];
//         return max(solve(nums,0,n-2), solve(nums,1,n-1));
//     }
// };


//tabulation
// class Solution {
// public:

//     int solve(vector<int>& nums, int start, int end){
//         int n = end - start + 1;
//         vector<int> dp(n);

//         dp[0] = nums[start];

//         if(n > 1)
//             dp[1] = max(nums[start], nums[start+1]);

//         for(int i = 2; i < n; i++){
//             int take = nums[start + i] + dp[i-2];
//             int skip = dp[i-1];
//             dp[i] = max(take, skip);
//         }

//         return dp[n-1];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1)
//             return nums[0];

//         int case1 = solve(nums, 0, n-2);
//         int case2 = solve(nums, 1, n-1);

//         return max(case1, case2);
//     }
// };

// memoization
// class Solution {
// public:

//     int solve(int i, int end, vector<int>& nums, vector<int>& dp){
//         if(i > end) return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         int take = nums[i] + solve(i+2, end, nums, dp);
//         int skip = solve(i+1, end, nums, dp);

//         return dp[i] = max(take, skip);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1)
//             return nums[0];

//         vector<int> dp1(n, -1);
//         vector<int> dp2(n, -1);

//         int case1 = solve(0, n-2, nums, dp1);
//         int case2 = solve(1, n-1, nums, dp2);

//         return max(case1, case2);
//     }
// };
