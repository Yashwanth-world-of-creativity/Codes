class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<int> result(n);
        int curr=0;
        for(int i=0;i<n;i++){
            int left=curr;
            curr+=nums[i];
            int right=sum-curr;
            result[i]=abs(left-right);
        }
        return result;
    }
};
