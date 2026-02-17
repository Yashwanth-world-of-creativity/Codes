class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
    
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

        vector<int> arr;   // <-- this was missing

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            arr.push_back(node);   // store processed node

            for(int &i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        return arr.size() == n;
    }
};

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);
        
//         for(auto &p : prerequisites){
//             int u = p[1];
//             int v = p[0];
//             adj[u].push_back(v);
//             indegree[v]++;
//         }
        
//         queue<int> q;
        
//         for(int i = 0; i < numCourses; i++){
//             if(indegree[i] == 0)
//                 q.push(i); //here we are pushing the vlues or node whose indegree is equal to 0
//         }
        
//         int count = 0;
        
//         while(!q.empty()){
//             int node = q.front();  // here front() value is stored in node
//             q.pop();
//             count++;
            
//             for(int &nbr : adj[node]){
//                 indegree[nbr]--;     //for every adj node we are decreasing its corresponding nodes visited by that node 
//                 if(indegree[nbr] == 0)
//                     q.push(nbr);
//             }
//         }
        
//         return count == numCourses;   // checking the condition for graph is acyclic graph....
//     }
// };
