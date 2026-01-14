class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        int xorNums = 0;

        
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }

        for (int i = 0; i < n; i++) {
            xorNums ^= nums[i];
        }

        return xorAll ^ xorNums;
    }
};
