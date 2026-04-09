class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0;

        // Phase 1: Advance p while strictly increasing
        while (p < n - 2 && nums[p] < nums[p + 1])
            p++;

        // Must have at least one increasing step
        if (p == 0) return false;

        int q = p;

        // Phase 2: Advance q while strictly decreasing
        while (q < n - 1 && nums[q] > nums[q + 1])
            q++;

        // Must have at least one decreasing step, and room for phase 3
        if (q == p || q == n - 1) return false;

        // Phase 3: Advance q while strictly increasing
        while (q < n - 1 && nums[q] < nums[q + 1])
            q++;

        // Must consume the entire remaining array
        return q == n - 1;
    }
};
