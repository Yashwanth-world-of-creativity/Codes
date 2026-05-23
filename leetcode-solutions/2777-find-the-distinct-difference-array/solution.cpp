class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> suffix;

        for (int num : nums) {

            suffix[num]++;
        }

        unordered_set<int> prefix;

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            prefix.insert(nums[i]);

            suffix[nums[i]]--;

            if (suffix[nums[i]] == 0) {

                suffix.erase(nums[i]);
            }

            ans.push_back(prefix.size() - suffix.size());
        }

        return ans;
    }
};
