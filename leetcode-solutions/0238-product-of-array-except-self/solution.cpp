class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int PL=1;
        int PR=1;
        vector<int> ans(n,1);
        for(int i=n-1;i>=0;i--){
            ans[i]=PR;
            PR=PR*nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]*=PL;
            PL=PL*nums[i];
    }
    return ans;
    }
};
