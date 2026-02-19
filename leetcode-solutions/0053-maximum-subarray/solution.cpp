//Kadence Algorithm - it states that if the array sum is < 0 then set it to zero because it is going to effect the future sub array or it will decrease the future subarray
class Solution{
    public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            maxSum=max(currSum,maxSum);
            if(currSum<0)
            currSum=0;
        }
        return maxSum;
    }
};

// Brute Froce
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int maxSum=INT_MIN;
//         for(int i=0;i<n;i++){
//             int currSum=0;
//             for(int j=i;j<n;j++){
//                 currSum+=nums[j];
//                 maxSum=max(currSum,maxSum);
//             }
//         }
//         return maxSum;
//     }
// };

