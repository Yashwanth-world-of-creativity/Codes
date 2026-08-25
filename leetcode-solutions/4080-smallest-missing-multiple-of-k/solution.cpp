class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        int ans;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i=1;i<=101;i++){
             ans=i*k;
            if(!st.count(ans)) return ans;
        }
        return ans;
    }
};
