class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(), nums.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(sumofD(nums,mid)<=threshold){
                    ans=mid;
                    r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
            int sumofD(vector<int>&nums,int mid){
                int sum=0;
                for(int i:nums){
                    sum+=ceil(double(i)/double(mid));
                }
                return sum;
            
        
    }
};
