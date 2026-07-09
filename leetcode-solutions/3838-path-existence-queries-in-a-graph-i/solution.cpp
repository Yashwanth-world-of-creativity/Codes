class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n,0);
        vector<bool>ans;
       int  count=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) count++;

            group[i]=count; 
        }
        for(auto &q:queries){
            if(group[q[0]]==group[q[1]]) ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};
