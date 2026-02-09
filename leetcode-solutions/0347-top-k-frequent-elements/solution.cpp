class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // store (frequency, number)
        vector<pair<int, int>> v;
        for (auto it : freq) {
            v.push_back({it.second, it.first});
        }

        // sort by frequency descending
        sort(v.begin(), v.end(), greater<>());

        // take top k
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
