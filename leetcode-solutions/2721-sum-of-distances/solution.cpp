class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for (auto &it : mp) {
            auto &v = it.second;
            int m = v.size();

            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = (long long)v[i] * i - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - (long long)v[i] * (m - i - 1);
                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};
