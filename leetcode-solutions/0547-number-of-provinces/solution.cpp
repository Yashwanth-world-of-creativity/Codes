class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int s){
        visited[s] = true;

        for(int i = 0; i < adj.size(); i++){
            if(adj[s][i] == 1 && !visited[i]){
                dfs(adj, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
             
                dfs(adj, visited, i);
                   ans++;
            }
        }

        return ans;
    }
};
