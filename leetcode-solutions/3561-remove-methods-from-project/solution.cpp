// class Solution {
// public:
//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
//     }
// };
class Solution {
public:
    void dfs1(int u, vector<vector<int>>& graph, vector<bool>& suspicious) {
        suspicious[u] = true;

        for (int v : graph[u]) {
            if (!suspicious[v])
                dfs1(v, graph, suspicious);
        }
    }

    void dfs2(int u, vector<vector<int>>& graph, vector<bool>& vis,
              vector<bool>& suspicious) {

        vis[u] = true;
        suspicious[u] = false;

        for (int v : graph[u]) {
            if (!vis[v])
                dfs2(v, graph, vis, suspicious);
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> directed(n);
        vector<vector<int>> undirected(n);

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            directed[u].push_back(v);

            undirected[u].push_back(v);
            undirected[v].push_back(u);
        }

        vector<bool> suspicious(n, false);

        dfs1(k, directed, suspicious);

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i])
                dfs2(i, undirected, vis, suspicious);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};
