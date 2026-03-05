// class Solution {
// public:

//     int solve(vector<int>& nums, int i, vector<int>& dp){

//         if(i < 0)
//             return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         int take = nums[i] + solve(nums, i-2, dp);
//         int skip = solve(nums, i-1, dp);

//         return dp[i] = max(take, skip);
//     }

//     int rob(vector<int>& nums) {

//         int n = nums.size();

//         vector<int> dp(n,-1);

//         return solve(nums, n-1, dp);
//     }
// };


//tabulation
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }

        return dp[n-1];
    }
};
// prev
// class Solution {
// public:
//     int rob(vector<int>& nums) {

//         int prev2 = 0;
//         int prev1 = 0;

//         for(int num : nums){
//             int curr = max(prev1, prev2 + num);

//             prev2 = prev1;
//             prev1 = curr;
//         }

//         return prev1;
//     }
// };
