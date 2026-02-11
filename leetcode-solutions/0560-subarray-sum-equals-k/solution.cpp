class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
           

        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for(int x : nums) {
            sum += x;

            if(mp.count(sum - k))
                count += mp[sum - k];

            mp[sum]++;
        }

        return count;
    }
};
    //     int count=0;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=nums[j];
    //             if(sum==k)
    //         count+=1;
    //         }
            
    //     }
    //     return count;
    // }
    // };
//     class Solution { Sliding Window.....
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left = 0, sum = 0, count = 0;

//         for(int right = 0; right < n; right++) {
//             sum += nums[right];

//             while(sum > k) {
//                 sum -= nums[left];
//                 left++;
//             }

//             if(sum == k)
//                 count++;
//         }

//         return count;
//     }
// };
   
