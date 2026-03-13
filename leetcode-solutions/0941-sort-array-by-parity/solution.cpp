class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l < r){
            if(nums[l] % 2 != 0 && nums[r] % 2 == 0){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            else if(nums[l] % 2 == 0){
                l++;
            }
            else{
                r--;
            }
        }

        return nums;
    }
};
