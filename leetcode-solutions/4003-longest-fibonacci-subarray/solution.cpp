class Solution {
public:

    int maxNum(vector<int>& nums, int maxlen, vector<int>& dp){

        int n = nums.size();
        int curr = 2;

        for(int i = 2; i < n; i++){

            if(nums[i] == nums[i-1] + nums[i-2]){
                curr++;
            }
            else{
                curr = 2;
            }

            maxlen = max(maxlen, curr);
        }

        return maxlen;
    }

    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        if(n < 2) return n;

        vector<int> dp(n+1, -1);

        int maxlen = 2;

        return maxNum(nums, maxlen, dp);
    }
};
//tabulation
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {

//         int n = nums.size();
//         if(n < 2) return n;

//         vector<int> dp(n, 2);

//         int maxLen = 2;

//         for(int i = 2; i < n; i++) {

//             if(nums[i] == nums[i-1] + nums[i-2]) {
//                 dp[i] = dp[i-1] + 1;
//             }
//             else {
//                 dp[i] = 2;
//             }

//             maxLen = max(maxLen, dp[i]);
//         }

//         return maxLen;
//     }
// };


// code for max element longest subarray
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {

//         int maxVal = *max_element(nums.begin(), nums.end());

//         int count = 0;
//         int maxLen = 0;

//         for(int num : nums) {

//             if(num == maxVal) {
//                 count++;
//                 maxLen = max(maxLen, count);
//             }
//             else {
//                 count = 0;
//             }
//         }

//         return maxLen;
//     }
// };
