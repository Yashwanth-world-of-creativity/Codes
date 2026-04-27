class Solution {
public:
    int m,n;

    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0,-1},{0,1}}},    
        {2, {{-1,0},{1,0}}},    
        {3, {{0,-1},{1,0}}},    
        {4, {{0,1},{1,0}}},     
        {5, {{0,-1},{-1,0}}},   
        {6, {{0,1},{-1,0}}}     
    };

    bool dfs(vector<vector<int>>& grid,int i,int j,
             vector<vector<bool>>& visited){

        if(i==m-1 && j==n-1)
            return true;

        visited[i][j]=true;

        for(auto &dir : directions[grid[i][j]]){

            int ni=i+dir[0];
            int nj=j+dir[1];

            if(ni<0 || ni>=m || nj<0 || nj>=n || visited[ni][nj])
                continue;

            // Can next cell connect back to current cell?
            for(auto &backDir : directions[grid[ni][nj]]){

                if(ni+backDir[0]==i && nj+backDir[1]==j){

                    if(dfs(grid,ni,nj,visited))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        return dfs(grid,0,0,visited);
    }
};
