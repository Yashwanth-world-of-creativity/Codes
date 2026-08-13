class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        for (int x = 1; x <= n; x++) {
            int cnt = 0;

            for (int num : nums) {
                if (num >= x)
                    cnt++;
            }

            if (cnt == x)
                return x;
        }

        return -1;
    }
};
