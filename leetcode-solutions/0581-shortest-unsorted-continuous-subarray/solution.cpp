class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mi=INT_MAX,mx=INT_MIN;
        bool flag =false;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])
            flag=true;
            if(flag)
            mi=min(mi,nums[i]);
        }
        flag=false;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
            flag=true;
            if(flag)
            mx=max(mx,nums[i]);
        }
        int l,r;
        for(l=0;l<n;l++){
            if(nums[l]>mi)
            break;
        }
        for(r=n-1;r>=0;r--){
            if(nums[r]<mx)
            break;
        }
        return r-l < 0 ? 0 : r-l + 1;
    }
};
