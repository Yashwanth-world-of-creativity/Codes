class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();

        for(auto &row : nums){
            for(int x : row){
                freq[x]++;
            }
        }

        vector<int> ans;

        for(auto &it : freq){
            if(it.second == n){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
