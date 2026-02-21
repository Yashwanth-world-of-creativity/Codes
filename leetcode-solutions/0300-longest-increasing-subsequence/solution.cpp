class Solution {
public:
    void binarySearch(vector<int> &res,int k){
        int l = 0, r = res.size()-1;
        int ind;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(res[mid]<k){
                l = mid+1;
            } else{
                ind = mid;
                r = mid-1;
            }
        }
        res[ind]=k;
    }
    int lengthOfLIS(vector<int>& nums) {
        int len=1, n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>res[len-1]){
                res.push_back(nums[i]);
                len++;
            }
            else{
                binarySearch(res,  nums[i]);
            }
        }
        return len;
    }
};
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> dp(n, 0);   // start with 0
//         int lis = 0;
        
//         for(int i = 0; i < n; i++) {
            
//             dp[i] = 1;  // every element alone is LIS = 1
            
//             for(int j = 0; j < i; j++) {
//                 if(nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);// if the no less than that exits then add +1
//                 }
//             }
            
//             lis = max(lis, dp[i]);
//         }
        
//         return lis;
//     }
// };
