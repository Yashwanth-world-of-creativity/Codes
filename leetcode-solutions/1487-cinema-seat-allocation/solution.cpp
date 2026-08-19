class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 5)
                mp[row] |= 1;

            if (col >= 4 && col <= 7)
                mp[row] |= 2;

            if (col >= 6 && col <= 9)
                mp[row] |= 4;
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            if (mask == 0)
                ans += 2;
            else if (mask == 7)
                ans += 0;
            else
                ans += 1;
        }

        return ans;
    }
};
