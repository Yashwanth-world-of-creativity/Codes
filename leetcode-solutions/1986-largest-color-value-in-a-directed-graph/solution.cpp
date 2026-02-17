class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        int N=colors.size();
        vector<int> indegree(N,0);
        for(auto &i:edges){
            int u = i[0];
            int v=i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        vector<vector<int>>t(N,vector<int>(26,0));//2d vector
        for(int i=0;i<N;i++){
            if(indegree[i]==0)
            {
                que.push(i);
                t[i][colors[i]-'a']=1;// i need index so -'a'
            }
        }
        int ans=0;
        int countN=0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            countN++;
            ans=max(ans,t[u][colors[u]-'a']);
            for(int &v:adj[u]){
            //for all the colors
for(int i=0;i<26;i++){
    t[v][i]=max(t[v][i],t[u][i]+(colors[v]-'a'==i));//same color then add 1 
}
            
            indegree[v]--;
            if(indegree[v]==0)
            que.push(v);
        }
        }

    if(countN<N)
    return -1;//cycle

return ans;
    }
};
