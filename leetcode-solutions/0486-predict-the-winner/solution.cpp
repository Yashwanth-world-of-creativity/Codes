// class Solution {
// public:
// int  solve(int i, int j ,vector<int>& nums){
//    if(i==j)

//             return nums[i];

//         int takeLeft = nums[i] - solve(i+1,j,nums);

//         int takeRight = nums[j] - solve(i,j-1,nums);

//         return max(takeLeft,takeRight);
// }
//     bool predictTheWinner(vector<int>& nums) {
//        int n=nums.size();
//         int total=accumulate(begin(nums),end(nums),0);
//         int take=solve(0,n-1,nums);
//         int notake=total-take;
//         if(take>=notake) return true;
//     return false;
//     }
// };
class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j) {

        if(i == j)
            return nums[i];

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int left = nums[i] - solve(nums, i + 1, j);
        int right = nums[j] - solve(nums, i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        dp.assign(n, vector<int>(n, INT_MIN));

        return solve(nums, 0, n - 1) >= 0;
    }
};
