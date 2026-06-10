// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
        
//     }
// };
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> maxT(LOG, vector<int>(n));
        vector<vector<int>> minT(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) maxT[0][i] = minT[0][i] = nums[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1 << j) <= n; i++) {
                maxT[j][i] = max(maxT[j-1][i], maxT[j-1][i+(1<<(j-1))]);
                minT[j][i] = min(minT[j-1][i], minT[j-1][i+(1<<(j-1))]);
            }

        auto qmax = [&](int l, int r) {
            int k = __lg(r-l+1);
            return max(maxT[k][l], maxT[k][r-(1<<k)+1]);
        };
        auto qmin = [&](int l, int r) {
            int k = __lg(r-l+1);
            return min(minT[k][l], minT[k][r-(1<<k)+1]);
        };
        auto val = [&](int l, int r) -> long long {
            return qmax(l,r) - qmin(l,r);
        };

        using T = tuple<long long,int,int>;
        priority_queue<T> pq;
        set<pair<int,int>> visited;  // ← track pushed subarrays

        auto push = [&](int l, int r) {
            if (l > r) return;
            if (visited.count({l, r})) return;  // ← skip duplicates
            visited.insert({l, r});
            pq.push({val(l, r), l, r});
        };

        push(0, n-1);

        long long ans = 0;
        while (k--) {
            auto [v, l, r] = pq.top(); pq.pop();
            ans += v;
            push(l, r-1);  // shrink right
            push(l+1, r);  // shrink left
        }

        return ans;
    }
};
