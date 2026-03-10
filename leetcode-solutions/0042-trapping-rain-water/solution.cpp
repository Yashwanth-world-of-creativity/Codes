class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int water = 0;
        int maxL = 0, maxR = 0;

        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] >= maxL)
                    maxL = height[l];
                else
                    water += maxL - height[l];

                l++;
            }
            else {
                if(height[r] >= maxR)
                    maxR = height[r];
                else
                    water += maxR - height[r];

                r--;
            }
        }

        return water;
    }
};
