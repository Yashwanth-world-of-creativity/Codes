
class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {

            int taken = i + 1;   // selecting i+1 students

            if(taken > nums[i] && nums[i + 1] > taken)
                ans++;
        }

        // Can we select all students?
        if(nums[n - 1] < n)
            ans++;

        // Can we select 0 students?
        if(nums[0] > 0)
            ans++;

        return ans;
    }
};

// class Solution {
// public:
//     int countWays(vector<int>& nums) {
//         int ans = 0;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             // Case 1: last element
//             if (i == n - 1 && nums[i] < i + 1) // 8 and nums[i] is 7
//                 ans++;

//             // Case 2: between two elements
//             else if (nums[i] < i + 1 && i + 1 < nums[i + 1])
//                 ans++;
//         }

//         // Case 3: selecting 0 students
//         if (nums[0] > 0)
//             return ans + 1;

//         return ans;
//     }
// };
