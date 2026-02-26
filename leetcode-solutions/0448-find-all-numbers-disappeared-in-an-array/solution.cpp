class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> result;
        
        // Count frequency
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        // Check which numbers from 1 to n are missing
        for(int i = 1; i <= n; i++) {
            if(mp.find(i) == mp.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

// class Solution {
// public:  // 1 ≤ nums[i] ≤ n
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             int index = abs(nums[i]) - 1;
//             if (nums[index] > 0) {
//                 nums[index] *= -1;
//             }
//         }
        
//         vector<int> result;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > 0) {
//                 result.push_back(i + 1);
//             }
//         }
        
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> ans;
//         set<int> st;
        
//         for(int i = 0; i < n; i++) {
//             st.insert(nums[i]);
//         }
        
//         for(int i = 1; i <= n; i++) {
//             if(st.find(i) == st.end()) {
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
// };
