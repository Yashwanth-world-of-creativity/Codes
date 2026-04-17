class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            int rem=(x % 10);
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
           

            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // store/update latest index
            mp[reverseNum(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
