class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
    
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build adjacency list + indegree
        for(auto &i : edges){
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push nodes with indegree 0
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;   // <-- this was missing

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);   // store processed node

            for(int &i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        if( ans.size() != n){
        return {};
        }
        else{
            return ans;
        }
    }
};
