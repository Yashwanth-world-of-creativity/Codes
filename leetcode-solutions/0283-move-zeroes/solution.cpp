
// two pointer method with single pointer moving forward
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;                            // position to place next non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);       // move non-zero forward
                j++;                          // only advance j now
            }
        }
        // no need for a second pass; swapping already pushes zeros to the end
    }
};
