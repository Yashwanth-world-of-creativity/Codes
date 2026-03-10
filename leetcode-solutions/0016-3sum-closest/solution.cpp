class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for(int k = 0; k < n - 2; k++) {

            int l = k + 1;
            int r = n - 1;

            while(l < r) {

                int sum = nums[k] + nums[l] + nums[r];

                if(abs(target - sum) < abs(target - closest))
                    closest = sum;

                if(sum < target)
                    l++;
                else if(sum > target)
                    r--;
                else
                    return sum;
            }
        }

        return closest;
    }
};
