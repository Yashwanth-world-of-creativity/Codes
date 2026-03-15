class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {

//         int n = nums.size();
//         vector<long long> prefix(n+1,0);

//         for(int i=1;i<=n;i++)
//             prefix[i] = prefix[i-1] + nums[i-1];

//         int ans = INT_MAX;

//         for(int i=0;i<n;i++){

//             long long need = target + prefix[i];

//             int j = lower_bound(prefix.begin()+i+1, prefix.end(), need) - prefix.begin();

//             if(j <= n)
//                 ans = min(ans , j - i);
//         }

//         if(ans == INT_MAX) return 0;

//         return ans;
//     }
// };
