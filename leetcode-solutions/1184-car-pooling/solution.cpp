class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1001, 0);

        for (auto& q : trips) {
            int passenger = q[0];
            int s = q[1];
            int e = q[2];
            pre[s] += passenger;
            if (e < 1000)
                pre[e] -= passenger;
        }
        int maxCap = pre[0];
        for (int i = 1; i <= 1000; ++i) {
            pre[i] += pre[i - 1];
            maxCap = max(maxCap, pre[i]);
        }
        return maxCap <= capacity;
    }
};

