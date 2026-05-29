class Solution {
public:
    int minElement(vector<int>& nums) {

        vector<int> ans;

        for (auto num : nums) {

            int sum = 0;

            while (num > 0) {

                sum += num % 10;
                num /= 10;
            }

            ans.push_back(sum);
        }

        return *min_element(ans.begin(), ans.end());
    }
};
