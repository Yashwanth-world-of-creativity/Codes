class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: build components
        for (auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }

        // Step 2: group indices
        unordered_map<int, unordered_map<int, int>> mp;

        for (int i = 0; i < n; i++) {
            int p = find(i);
            mp[p][source[i]]++;
        }

        // Step 3: match with target
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int p = find(i);

            if (mp[p][target[i]] > 0) {
                mp[p][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};
