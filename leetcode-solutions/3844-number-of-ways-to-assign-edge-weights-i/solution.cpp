// class Solution {
// public:
//     int assignEdgeWeights(vector<vector<int>>& edges) {
        
//     }
// };

//op
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int depth = -1;

        while (!q.empty()) {

            int sz = q.size();
            depth++;

            while (sz--) {

                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {

                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }
        }

        if (depth == 0) {
            return 1;
        }

        return power(2, depth - 1);
    }
};
