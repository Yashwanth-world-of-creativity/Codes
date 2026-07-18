class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max) max=nums[i];
            if(nums[i]<min) min=nums[i];
        }
        return __gcd(min,max);
    }
};
