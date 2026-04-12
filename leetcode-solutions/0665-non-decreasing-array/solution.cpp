class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0; // number of fixes made

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) { // violation found
                count++;
                if (count > 1) return false;

                // Decide which element to fix:
                // If i == 0 or left neighbor is safe, lower nums[i]
                // Otherwise raise nums[i+1]
                if (i == 0 || nums[i - 1] <= nums[i + 1])
                    nums[i] = nums[i + 1]; // lower the peak
                else
                    nums[i + 1] = nums[i]; // raise the dip
            }
        }
        return true;
    }
};
