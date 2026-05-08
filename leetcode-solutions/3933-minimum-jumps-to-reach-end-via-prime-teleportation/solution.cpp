class Solution {
public:
    vector<int> smallestPrimeFactor(int maxVal) {
        vector<int> spf(maxVal + 1);

        for (int i = 0; i <= maxVal; i++)
            spf[i] = i;

        for (long long i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        return spf;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf = smallestPrimeFactor(mx);

        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> used;

            while (x > 1) {
                int p = spf[x];

                if (!used.count(p)) {
                    bucket[p].push_back(i);
                    used.insert(p);
                }

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> vis(n, 0);

        queue<int> q;

        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return jumps;

                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                int val = nums[i];

                if (val > 1 && spf[val] == val) {

                    for (int nxt : bucket[val]) {

                        if (!vis[nxt]) {
                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                    }

                    bucket[val].clear();
                }
            }

            jumps++;
        }

        return -1;
    }
};
